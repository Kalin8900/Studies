//
// Created by Kalin on 22.05.2020.
//

#include "image.h"
#include <fstream>
#include <memory>
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

/******numbReceiver******/

numbReceiver &numbReceiver::getReceiver() //only one object in program
{
    static numbReceiver reciv;
    return reciv;
}

void numbReceiver::clearAllMem()
{
    receiversMapA.clear();
    receiversMapC.clear();
    specialSignsMap.clear();
}

numbReceiver::~numbReceiver()
{
    if(!receiversMapA.empty() || !receiversMapC.empty() || !specialSignsMap.empty())
        clearAllMem();
}

//save numbers and vectors to maps

void numbReceiver::registerNumberA(const unsigned int &number, const vector<unsigned char> &vec)
{
    receiversMapA.insert({number, vec});
}

void numbReceiver::registerNumberC(const unsigned int &number, const vector<unsigned char> &vec)
{
    receiversMapC.insert({number, vec});
}

void numbReceiver::registerSpecialSign(const string &signName, const vector<unsigned char> &vec)
{
    specialSignsMap.insert({signName, vec});
}

//initialise receiver

void numbReceiver::initReceiver()
{
    registerSpecialSign("startStop", {0, 1, 0});
    registerSpecialSign("separator", {1, 0, 1, 0, 1});

    registerNumberA(0, {1, 1, 1, 0, 0, 1, 0});
    registerNumberA(1, {1, 1, 0, 0, 1, 1, 0});
    registerNumberA(2, {1, 1, 0, 1, 1, 0, 0});
    registerNumberA(3, {1, 0, 0, 0, 0, 1, 0});
    registerNumberA(4, {1, 0, 1, 1, 1, 0, 0});
    registerNumberA(5, {1, 0, 0, 1, 1, 1, 0});
    registerNumberA(6, {1, 0, 1, 0, 0, 0, 0});
    registerNumberA(7, {1, 0, 0, 0, 1, 0, 0});
    registerNumberA(8, {1, 0, 0, 1, 0, 0, 0});
    registerNumberA(9, {1, 1, 1, 0, 1, 0, 0});

    registerNumberC(0, {0, 0, 0, 1, 1, 0, 1});
    registerNumberC(1, {0, 0, 1, 1, 0, 0, 1});
    registerNumberC(2, {0, 0, 1, 0, 0, 1, 1});
    registerNumberC(3, {0, 1, 1, 1, 1, 0, 1});
    registerNumberC(4, {0, 1, 0, 0, 0, 1, 1});
    registerNumberC(5, {0, 1, 1, 0, 0, 0, 1});
    registerNumberC(6, {0, 1, 0, 1, 1, 1, 1});
    registerNumberC(7, {0, 1, 1, 1, 0, 1, 1});
    registerNumberC(8, {0, 1, 1, 0, 1, 1, 1});
    registerNumberC(9, {0, 0, 0, 1, 0, 1, 1});
}

//receives number wrote in EAN code from receiver

std::vector<unsigned char> numbReceiver::getNumInCodeA(const unsigned int &number)
{
    const auto it = receiversMapA.find(number);
    if(it != receiversMapA.end())
        return it->second;
    throw std::runtime_error("Unknown number passed to receiver");
}

std::vector<unsigned char> numbReceiver::getNumInCodeC(const unsigned int &number)
{
    const auto it = receiversMapC.find(number);
    if(it != receiversMapC.end())
        return it->second;
    throw std::runtime_error("Unknown number passed to receiver");
}

std::vector<unsigned char> numbReceiver::getSpecialSignCode(const std::string &signName)
{
    const auto it = specialSignsMap.find(signName);
    if(it != specialSignsMap.end())
        return it->second;
    throw std::runtime_error("Unknown sign name passed to receiver");
}

/******image******/

//some data that specifies the BMP format

void image::initHeader()
{
    imgHeader.bfType = 0x4D42;
    imgHeader.bfSize = sizeof(bmpHeader);
    imgHeader.bfReserved1 = 0;
    imgHeader.bfReserved2 = 0;
    imgHeader.bfOffBits = sizeof(bmpHeader);
    imgHeader.biSize = 40;
    imgHeader.biWidth = static_cast<int>(imgWidth);
    imgHeader.biHeight = static_cast<int>(imgHeight);
    imgHeader.biPlanes = 1;
    imgHeader.biBitCount = 1;
    imgHeader.biCompression = 0;
    imgHeader.biSizeImage = lineInBytes * imgHeight;
    imgHeader.biXPelsPerMeter = 11811;
    imgHeader.biYPelsPerMeter = 11811;
    imgHeader.biClrUsed = 2;
    imgHeader.biClrImportant = 0;
    imgHeader.RGBQuad_0 = 0x00000000;
    imgHeader.RGBQuad_1 = 0x00FFFFFF;
}

image::image(const unsigned int &width, const unsigned int &height, vector<unsigned int> numb)
        : imgWidth(width),
          imgHeight(height),
          lineInBytes((width + 31) / 32 * 4),
          digits(std::move(numb))
{
    initHeader();

    numbReceiver::getReceiver().initReceiver();

    imgPixels = new unsigned char[lineInBytes * imgHeight];

    memset(imgPixels, 0xFF, lineInBytes * imgHeight);
}

image::~image()
{
    if(imgPixels)
        clearMem();
}

void image::clearMem()
{
    delete[] imgPixels;
}

int image::saveBMP(const std::string &fname)
{
    ofstream ofs{fname, fstream::binary};

    ofs.write(reinterpret_cast<char *>(&imgHeader), sizeof(bmpHeader));

    unsigned char *ptr;

    ptr = imgPixels + lineInBytes * (imgHeight - 1);

    for(unsigned int y = imgHeight; y > 0; --y, ptr -= lineInBytes)
        ofs.write(reinterpret_cast<char *>(ptr), lineInBytes);

    ofs.close();

    return 0;
}

void image::setPixel(unsigned int x, unsigned int y, unsigned char value)
{
    if(x >= imgWidth || y >= imgHeight)
        throw invalid_argument("Cannot set pixel in this position");

    unsigned char *pPix = imgPixels + (lineInBytes * y + (x >> 3)); //gets a pixel to set
    unsigned char mask = 0x80 >> (x & 0x07); //bitmask
    if(value)
        *pPix |= mask;
    else
        *pPix &= ~mask;
}

//control number is a typical -S mod 10 function
unsigned int image::getControlNumber()
{
    unsigned int sum = 0, ans;
    for(bool odd = true; const auto &elem : digits)
    {
        sum += (odd) ? 3 * elem : elem;
        odd = !odd;
    }
    ans = 10 - sum % 10;
    return (ans == 10) ? 0 : ans;
}

//const margin value 5% width
unsigned int getMargins(const unsigned int &width)
{
    return floor(width * 0.05);
}

//makes a column from top to bottom in given color
void image::generateCol(const unsigned int &xPos, const unsigned int &length, const unsigned char &val)
{
    for(unsigned int x = xPos; x < xPos + length; ++x)
        for(unsigned int y = 0; y < imgHeight; ++y)
            setPixel(x, y, val);
}


//creates whole EAN barcode ready to save
void image::generateEAN()
{
    if(digits.size() != 7)
        throw runtime_error("Cannot generate EAN-8 code from different numbers of digits than 7");

    unsigned int widthWithMargins = imgWidth - getMargins(imgWidth);
    unsigned int oneBitWidth = ceil(widthWithMargins / (8 * 7 + 11)); //6 is a start + stop bit sum and 5 is a separator
    if(oneBitWidth < 1)
        throw runtime_error("Width is too small to generate the EAN-8 code");
    unsigned int x = getMargins(imgWidth);

    //start sign
    for(const auto &bit : numbReceiver::getReceiver().getSpecialSignCode("startStop"))
    {
        generateCol(x, oneBitWidth, bit);
        x += oneBitWidth;
    }

    //numbers in A code
    for(unsigned int i = 0; i < 4; ++i) //4 first digits in EAN-8 are in A code
    {
        for(const auto &bit : numbReceiver::getReceiver().getNumInCodeA(digits.at(i)))
        {
            generateCol(x, oneBitWidth, bit);
            x += oneBitWidth;
        }
    }

    //separator sign
    for(const auto &bit : numbReceiver::getReceiver().getSpecialSignCode("separator"))
    {
        generateCol(x, oneBitWidth, bit);
        x += oneBitWidth;
    }

    //numbers in C code
    for(unsigned int i = 4; i < digits.size(); ++i) //others are in C code
    {
        for(const auto &bit : numbReceiver::getReceiver().getNumInCodeC(digits.at(i)))
        {
            generateCol(x, oneBitWidth, bit);
            x += oneBitWidth;
        }
    }
    //control digit in C code
    for(const auto &bit : numbReceiver::getReceiver().getNumInCodeC(getControlNumber()))
    {
        generateCol(x, oneBitWidth, bit);
        x += oneBitWidth;
    }

    //stop sign
    for(const auto &bit : numbReceiver::getReceiver().getSpecialSignCode("startStop"))
    {
        generateCol(x, oneBitWidth, bit);
        x += oneBitWidth;
    }
}

