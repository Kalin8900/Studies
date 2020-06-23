//
// Created by Kalin on 22.05.2020.
//

#ifndef ZAD_8_IMAGE_H
#define ZAD_8_IMAGE_H

#include <string>

//struct was given also with C program.
#pragma pack(push, 1)
struct bmpHeader
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
    unsigned int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
};
#pragma pack(pop)

class image
{
public:
    image(const int &width, const int &height); //bmpHeader is not filled by this constructor!

    image() {};

    ~image();

    void readBMP(const std::string &fname); //binary read from stream and passing data to class

    int saveBMP(const std::string &fname); //bianry save by stream from the class, unfortunately bmpHeader
    //init is neded inside

    void clearMem(); //memory deallocation

    unsigned char getPixel(unsigned int x, unsigned int y); //receive a pointer to pixel in imgPixels array

    void setPixel(unsigned int x,
                  unsigned int y, unsigned char value); //set pixel in imgPixels array

    void medianFilter(); //removes some interferences on the image

private:
    unsigned int imgWidth, imgHeight, lineInBytes;
    unsigned char *imgPixels;
    bmpHeader imgHeader;
};


#endif //ZAD_8_IMAGE_H
