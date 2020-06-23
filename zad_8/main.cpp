#include <iostream>
#include "image.h"

using namespace std;

int main(int argc, char *argv[])
{

    if(sizeof(bmpHeader) != 54)
    {
        cout << "Change compilation options so as bmpHdr struct size is 62 bytes. Current size is: "
             << sizeof(bmpHeader);
        return -1;
    }

    if(argc < 3)
    {
        cout << argv[0] << " input_file_name output_file_name" << endl;
        return -2;
    }

    image img;

    img.readBMP(argv[1]);

//    saving, reading tests is in comment
    int w = 50, h = 30;

    for(unsigned int y = 100; y < 150; ++y)
        for(unsigned int x = 100; x < 150; ++x)
            img.setPixel(x, y, 128);

    unsigned int org_x = 262, org_y = 262;
    image smallImg(w, h);

    for(unsigned int y = 0; y < h; ++y)
        for(unsigned int x = 0; x < w; ++x)
            smallImg.setPixel(x, y, img.getPixel(org_x + x, org_y + y));

    smallImg.saveBMP("smallImg.bmp");

    //median filter tests
    img.medianFilter();
    img.saveBMP(argv[2]);

    //clearMem is also called in destructor if memory is not cleared in main
    img.clearMem();
    smallImg.clearMem();
    return 0;
}
