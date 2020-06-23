#include <iostream>
#include <sstream>
#include "image.h"

using namespace std;

const int bmpHeaderRequiredSize = 62;

int main(int argc, char *argv[])
{
    if(sizeof(bmpHeader) != bmpHeaderRequiredSize)
    {
        cout << "Change compilation options so as bmpHdr struct size is 62 bytes. Current size is: "
             << sizeof(bmpHeader);
        return -1;
    }

    //Control number tests

    {
        vector<vector<unsigned int>> controlNumberTest = {
                {9, 6, 3, 8, 5, 0, 7},
                {3, 0, 4, 5, 4, 1, 2},
                {1, 2, 3, 4, 5, 6, 7},
                {0, 9, 8, 8, 7, 6, 5},
                {6, 5, 4, 1, 1, 3, 5},
                {5, 1, 6, 4, 9, 8, 4}};
        vector<unsigned int> controlNumberAns = {4, 5, 0, 7, 3,
                                                 5}; //answers from http://www.axicon.com/checkdigitcalculator.html
        int errCnt = 0;
        for(int ansIndex = 0; const auto &package : controlNumberTest)
        {
            image testImage(50, 50, package);

            if(testImage.getControlNumber() != controlNumberAns.at(ansIndex))
            {
                cout << "Error in " << ansIndex << " test set. Control number is wrong!" << endl;
                cout << testImage.getControlNumber() << " != " << controlNumberAns.at(ansIndex) << endl;
                ++errCnt;
            }
            ++ansIndex;

            testImage.clearMem();
        }

        if(errCnt != 0)
        {
            cout << "Program does not work properly. Shutdown";
            return -1;
        }
    }

    if(argc < 2)
    {
        cout << "Wrong usage. Proper fromat is" << argv[0] << " output_file_name" << endl;
        return -2;
    }

    vector<unsigned int> numbers;

    cout << "Enter 7 digits (one by one!) of the EAN-8 code" << endl;
    int digit;
    while(numbers.size() != 7)
    {
        try
        {
            for(unsigned int i = 0; i < 7; ++i)
            {
                cin >> digit;
                if(digit > 9)
                    throw invalid_argument("You passed wrong digit. It must be from <0, 9>. "
                                           "Remember to pass number one by one");
                numbers.push_back(digit);
            }
        }
        catch(invalid_argument &ex)
        {
            numbers.clear();
            cout << ex.what() << endl;
            cout << "Enter digits again" << endl;
        }
    }


    unsigned int width = 0, height = 0, sWidth, sHeight;
    cout << "Enter the width and height of the image" << endl;
    do
    {
        try
        {
            cin >> sWidth >> sHeight;
            if(sWidth < 60)
                throw invalid_argument("The width is too small to generate an EAN-8 code");
            if(sHeight < 30)
                throw invalid_argument("The height is too small to generate an EAN-8 code");
            width = sWidth;
            height = sHeight;
        }
        catch(invalid_argument &ex)
        {
            width = 0;
            height = 0;
            cout << ex.what() << endl;
            cout << "Enter width and height again" << endl;
        }
    } while(width == 0 || height == 0);


    image img(width, height, numbers);

    img.generateEAN();

    img.saveBMP(argv[1]);

    img.clearMem();

    cout << "Created image " << argv[1];

    return 0;
}
