#include "drawing.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace Graph_lib;

#define PI 3.14159265359



bool approximatelyEqual(float a, float b) //To compare matrix
{
    return std::fabs(a - b) <= 0.0001;
}

int main()
{
    { //quick display test
        Matrix<float> mt;
        stringstream ss;
        std::string ans = "1 0 0 \n0 1 0 \n0 0 1 \n"; //Identity matrix
        ss << mt;
        if(ans != ss.str())
            cout << "<< operator error" << endl;
        else
            cout << "<< operator is good" << endl;
    }

    { //quick operators test
        Matrix<float> ma;
        std::vector<std::vector<std::vector<float>>> simply =
                {{{0.866025, 0.5, 0}, {-0.5, 0.866025, 0}, {0,    0,    1}}, //rotation 30 deg
                 {{1,        0,   0}, {0,    1,        0}, {4.75, 8.23, 1}}, //transition 4.75, 8.23
                 {{10.63,    0,   0}, {0,    7.32,     0}, {0,    0,    1}}}; //scale 10.63, 7.32
        std::vector<std::vector<std::vector<float>>> complicated = //values calculated by matrix calculator
                {{{11.10894777, 3.668055336, 0}, //operator *
                  {-5.34978972, 7.616791926, 0},
                  {85.45, 96.35, 1}},
                 {{1, 0, 0},{0, 1, 0},{57.22, -433.71, 1}}}; //operator *=

        for(int i = 0; i < simply.size(); ++i)
        {
            int errcnt = 0;
            if(i == 0)
                ma = ma.rotateMx( PI / 6.0);
            if(i == 1)
                ma = ma.translateMx(4.75, 8.23);
            if(i == 2)
                ma = ma.scaleMx(10.63, 7.32);
            for(int row = 0; row < 3; ++row)
            {
                for(int rowElem = 0; rowElem < 3; ++rowElem)
                {
                    if(!approximatelyEqual(ma.getArr().at(row).at(rowElem), simply.at(i).at(row).at(rowElem)))
                        ++errcnt;
                }
            }
            if(errcnt != 0)
                cout << "Something is not working with matrix num " << i << endl << ma << endl;
        }

        for(int i = 0; i < complicated.size(); ++i)
        {
            Matrix<float> mw;
            int errcnt = 0;
            if(i == 0)
                mw = Matrix<float>::rotateMx( PI / 7.0) *
                        Matrix<float>::scaleMx(12.33, 8.454) *
                        Matrix<float>::translateMx(85.45, 96.35);
            if(i == 1)
                mw *= Matrix<float>::translateMx(15.53, -759.45) *
                        Matrix<float>::translateMx(41.69, 325.74);
            for(int row = 0; row < 3; ++row)
            {
                for(int rowElem = 0; rowElem < 3; ++rowElem)
                {
                    if(!approximatelyEqual(mw.getArr().at(row).at(rowElem), complicated.at(i).at(row).at(rowElem)))
                        ++errcnt;
                }
            }
            if(errcnt != 0)
                cout << "Something is not working with matrix num " << i << endl << mw << endl;
        }
    }


    myWindow wnd(Point(100, 100), 600, 400,
                 window_title(), "house.txt");
    gui_main();


    return 0;
}
