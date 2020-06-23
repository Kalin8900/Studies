//
// Created by Kalin on 22.05.2020.
//

#ifndef ZAD_8_IMAGE_H
#define ZAD_8_IMAGE_H

#include <string>
#include <array>
#include <vector>
#include <map>

#pragma pack(push, 1)
struct bmpHeader //struct from program in C. Describes BMP format
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
    unsigned int RGBQuad_0;
    unsigned int RGBQuad_1;
};
#pragma pack(pop)

//class which gives an EAN code from given number
class numbReceiver
{
public:
    static numbReceiver &getReceiver(); //only one object in whole program

    ~numbReceiver();

    void clearAllMem(); //memory deallocation

    numbReceiver(const numbReceiver &) = delete;

    numbReceiver &operator=(const numbReceiver &) = delete;

    void initReceiver(); //loads receiver with data

    std::vector<unsigned char> getNumInCodeA(const unsigned int &number);

    std::vector<unsigned char> getNumInCodeC(const unsigned int &number);

    std::vector<unsigned char> getSpecialSignCode(const std::string &signName);

private:

    typedef std::map<unsigned int, std::vector<unsigned char>> receivers;
    receivers receiversMapA; //numbers coded in EAN-8A
    receivers receiversMapC; //numbers coded in EAN-8C
    std::map<std::string, std::vector<unsigned char>> specialSignsMap; //special signs like start, stop

    numbReceiver() = default;

    //methods which initalise maps in receiver

    void registerNumberA(const unsigned int &number, const std::vector<unsigned char> &vec);

    void registerNumberC(const unsigned int &number, const std::vector<unsigned char> &vec);

    void registerSpecialSign(const std::string &signName, const std::vector<unsigned char> &vec);
};


class image
{
public:
    image(const unsigned int &width, const unsigned int &height,
          std::vector<unsigned int> numb); //creates and allocates memory for image

    ~image();

    void initHeader(); //save data to bmp format

    int saveBMP(const std::string &fname); //save image to file by binary streams

    void clearMem();

    unsigned int getControlNumber(); //returns control number which is last in the EAN-8

    void setPixel(unsigned int x,
                  unsigned int y, unsigned char value); //set pixel in given color in imgPixels array

    void generateEAN(); //generates image ready to save in imgPixels array

private:

    unsigned int imgWidth, imgHeight, lineInBytes;
    unsigned char *imgPixels;
    bmpHeader imgHeader;
    std::vector<unsigned int> digits;

    //helper method to generateEAN()
    void generateCol(const unsigned int &xPos, const unsigned int &oneBitWidth, const unsigned char &val);
};


#endif //ZAD_8_IMAGE_H
