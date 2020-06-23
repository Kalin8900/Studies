//
// Created by Kalin on 22.05.2020.
//

#include "image.h"
#include <fstream>
#include <memory>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

image::image(const int &width, const int &height)
        : imgWidth(static_cast<unsigned int>(width)),
          imgHeight(static_cast<unsigned int>(height)),
          lineInBytes(static_cast<unsigned int>(width) + 3 & 0xFFFFFFFC)
{
    if(width <= 0 || height <= 0 || width >= 512 || height >= 512)
        throw invalid_argument("image cant be created with this arguments\n Here are the requirements \n "
                               "width > 0 && height > 0 && width < 512 && height < 512");

    imgPixels = new unsigned char[lineInBytes * imgHeight];

    memset(imgPixels, 0xFF, (((imgWidth + 31) >> 5) << 2) * imgHeight);
}

void image::readBMP(const std::string &fname)
{
    int lineBytes, imageSize;
    unsigned char *ptr;

    ifstream ifs{fname, fstream::binary};

    ifs.read(reinterpret_cast<char *>(&imgHeader), sizeof(bmpHeader));

    // a few checks
    if(imgHeader.bfType != 0x4D42 ||
       imgHeader.biPlanes != 1 ||
       imgHeader.biBitCount != 8)
    {
        throw runtime_error("Couldn't load a bmp file");
    }

    imgWidth = imgHeader.biWidth;
    imgHeight = abs(imgHeader.biHeight);
    lineInBytes = imgWidth;
    if(imgWidth % 4 != 0)
        lineInBytes += 4 - (imgWidth % 4);
    imageSize = static_cast<int>(imgHeader.biSizeImage);

    imgPixels = new unsigned char[imageSize];

    // process height (it can be negative)
    ptr = imgPixels;
    lineBytes = imgWidth + 3 & 0xFFFFFFFC; // line size in bytes
    if(imgHeader.biHeight > 0)
    {
        // "upside down", bottom of the image first
        ptr += lineBytes * (imgHeader.biHeight - 1);
        lineBytes = -lineBytes;
    }

    // reading image
    // moving to the proper position in the file

    ifs.seekg(imgHeader.bfOffBits, fstream::beg);

    for(int y = 0; y < imgHeight; ++y)
    {
        ifs.read(reinterpret_cast<char *>(ptr), abs(lineBytes));
        ptr += lineBytes;
    }

    ifs.close();
}

int image::saveBMP(const std::string &fname)
{
    int lineBytes = static_cast<int>(lineInBytes);
    int imgSize = lineBytes * static_cast<int>(imgHeight);
    int lookUpSize = 256 * sizeof(unsigned int);

    bmpHeader bmpHead =
            {
                    0x4D42,                // unsigned short bfType;
                    sizeof(bmpHeader) + lookUpSize + imgSize,        // unsigned long  bfSize;
                    0, 0,                // unsigned short bfReserved1, bfReserved2;
                    sizeof(bmpHeader) + lookUpSize,    // unsigned long  bfOffBits;
                    40,                            // unsigned long  biSize;
                    static_cast<int>(imgWidth),        // long  biWidth;
                    static_cast<int>(imgHeight),        // long  biHeight;
                    1,                    // short biPlanes;
                    8,                    // short biBitCount;
                    0,                    // unsigned long  biCompression;
                    static_cast<unsigned int>(imgSize), // unsigned long  biSizeImage;
                    11811,                // long biXPelsPerMeter; = 300 dpi
                    11811,                // long biYPelsPerMeter;
                    0,                    // unsigned long  biClrUsed;
                    0,                    // unsigned long  biClrImportant;
            };
    unsigned int lookUpTable[256];
    unsigned char *ptr;

    ofstream ofs{fname, fstream::binary};

    ofs.write(reinterpret_cast<char *>(&bmpHead), sizeof(bmpHeader));

    // initialize lookup
    for(uint32_t idx = 0; idx < 256; ++idx)
        lookUpTable[idx] = (idx << 16) | (idx << 8) | idx;

    ofs.write(reinterpret_cast<char *>(lookUpTable), 256 * sizeof(unsigned int));

    ptr = imgPixels + lineBytes * (imgHeight - 1);

    for(unsigned int y = imgHeight; y > 0; --y, ptr -= lineBytes)
        ofs.write(reinterpret_cast<char *>(ptr), lineBytes);

    ofs.close();
    return 0;
}

void image::clearMem()
{
    delete[] imgPixels;
}

image::~image()
{
    if(imgPixels != nullptr)
        clearMem();
}

unsigned char image::getPixel(unsigned int x, unsigned int y)
{
    if(x >= imgWidth || y >= imgHeight)
        return 0;
    // y - liczba wierszy poprzedzajacych aktualny!
    return imgPixels[y * lineInBytes + x];
}

void image::setPixel(unsigned int x, unsigned int y, unsigned char value)
{
    if(x >= imgWidth || y >= imgHeight)
        throw invalid_argument("Cannot set pixel in this position");
    imgPixels[y * lineInBytes + x] = value;
}


void image::medianFilter()
{
    std::vector<unsigned char> pixelsSquare;
    int h = static_cast<int>(imgHeight);
    int w = static_cast<int>(imgWidth);

    auto *res = imgPixels;
    for(int y = 0; y < h; ++y)
        for(int x = 0; x < w; ++x)
        {
            for(int windowY = y - 1; windowY < y + 2; ++windowY)
                for(int windowX = x - 1; windowX < x + 2; ++windowX)
                {
                    if(windowY > -1 && windowY < h && windowX < w && windowX > -1)
                        pixelsSquare.push_back(getPixel(windowX, windowY));
                }

            sort(pixelsSquare.begin(), pixelsSquare.end());

            res[y * lineInBytes + x] = pixelsSquare.at(pixelsSquare.size() / 2);

            pixelsSquare.clear();
        }
}
