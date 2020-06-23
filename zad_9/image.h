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

class numbReceiver
{
public:
    static numbReceiver &getReceiver();

    ~numbReceiver();

    void clearAllMem();

    numbReceiver(const numbReceiver &) = delete;

    numbReceiver &operator=(const numbReceiver &) = delete;

    void initReceiver();

    void registerNumberA(const unsigned int &number, const std::vector<unsigned char> &vec);

    void registerNumberC(const unsigned int &number, const std::vector<unsigned char> &vec);

    void registerSpecialSign(const std::string &signName, const std::vector<unsigned char> &vec);

    std::vector<unsigned char> getNumInCodeA(const unsigned int &number);

    std::vector<unsigned char> getNumInCodeC(const unsigned int &number);

    std::vector<unsigned char> getSpecialSignCode(const std::string &signName);

private:

    typedef std::map<unsigned int, std::vector<unsigned char>> receivers;
    receivers receiversMapA;
    receivers receiversMapC;
    std::map<std::string, std::vector<unsigned char>> specialSignsMap;

    numbReceiver() = default;
};

class image
{
public:
    image(const unsigned int &width, const unsigned int &height,
          std::vector<unsigned int> numb);

    ~image();

    void initHeader();

    int saveBMP(const std::string &fname);

    void clearMem();

    unsigned int getControlNumber();

    void setPixel(unsigned int x,
                  unsigned int y, unsigned char value);

    void generateEAN();

    void generateCol(const unsigned int &xPos, const unsigned int &oneBitWidth, const unsigned char &val);

private:
    unsigned int imgWidth, imgHeight, lineInBytes;
    unsigned char *imgPixels;
    bmpHeader imgHeader;
    std::vector<unsigned int> digits;
};


#endif //ZAD_8_IMAGE_H
