#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <iostream>

// Prosze Panstwa,
// uzupelnilem braki w materiale do cwiczen:
// - dodalem funkcje saveBMP, ktora zapisuje bitmape do pliku
// - zmodyfikowalem sposob liczenia line_bytes - okazalo sie, ze byl tam blad
// - dodalem funkcje InitImage, ktora tworzy nowa (biala) bitmape
// - dodalem fragment kodu, ktory wycina oko Leny i zapisuje w pliku wynikowym
// Pomyslalem, ze latwiej bedzie dzialac z mniejszym obrazkiem, niz 512x512.
// Mozna zmodyfikowac ten kod i we wstepnych testach klasy poslugiwac sie
// jeszcze mniejszym obrazem.
// Z pozdrowieniami,
// rkz

typedef struct
{
    unsigned int width, height;
    unsigned int line_bytes;
    unsigned char *pImg;
} imgInfo;

#pragma pack(push, 1)
typedef struct
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    int16_t biPlanes;
    int16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} bmpHdr;
#pragma pack(pop)

void *freeResources(FILE *pFile, void *pFirst, void *pSnd)
{
    if(pFile != 0)
        fclose(pFile);
    if(pFirst != 0)
        free(pFirst);
    if(pSnd != 0)
        free(pSnd);
    return 0;
}

imgInfo *readBMP(const char *fname)
{
    imgInfo *pInfo = 0;
    FILE *fbmp = 0;
    bmpHdr bmpHead;
    int lineBytes, imageSize = 0;
    unsigned int y;
    unsigned char *ptr;

    pInfo = 0;
    fbmp = fopen(fname, "rb");
    if(fbmp == NULL)
        return 0;

    fread((void *) &bmpHead, sizeof(bmpHead), 1, fbmp);
    // a few checks
    if(bmpHead.bfType != 0x4D42 ||
       bmpHead.biPlanes != 1 ||
       bmpHead.biBitCount != 8 ||
       (pInfo = (imgInfo *) malloc(sizeof(imgInfo))) == NULL)
        return (imgInfo *) freeResources(fbmp, pInfo, 0);


    pInfo->width = bmpHead.biWidth;
    pInfo->height = abs(bmpHead.biHeight);
    pInfo->line_bytes = pInfo->width;
    if(pInfo->width % 4 != 0)
        pInfo->line_bytes += 4 - (pInfo->width % 4);
    imageSize = bmpHead.biSizeImage;

    if((pInfo->pImg = (unsigned char *) malloc(imageSize)) == 0)
        return (imgInfo *) freeResources(fbmp, pInfo->pImg, pInfo);

    // process height (it can be negative)
    ptr = pInfo->pImg;
    lineBytes = (pInfo->width + 3) & 0xFFFFFFFC; // line size in bytes
    if(bmpHead.biHeight > 0)
    {
        // "upside down", bottom of the image first
        ptr += lineBytes * (bmpHead.biHeight - 1);
        lineBytes = -lineBytes;
    }

    // reading image
    // moving to the proper position in the file
    if(fseek(fbmp, bmpHead.bfOffBits, SEEK_SET) != 0)
        return (imgInfo *) freeResources(fbmp, pInfo->pImg, pInfo);


    for(y = 0; y < pInfo->height; ++y)
    {
        fread(ptr, 1, abs(lineBytes), fbmp);
        ptr += lineBytes;
    }


    fclose(fbmp);
    return pInfo;
}

imgInfo *InitImage(int w, int h)
{
    if(w <= 0 || h <= 0 || w >= 512 || h >= 512)
        return 0;
    imgInfo *pImg;
    if((pImg = (imgInfo *) malloc(sizeof(imgInfo))) == 0)
        return 0;
    pImg->height = h;
    pImg->width = w;
    pImg->line_bytes = (w + 3) & 0xFFFFFFFC;
    pImg->pImg = (unsigned char *) malloc(pImg->line_bytes * h);
    if(pImg->pImg == 0)
    {
        free(pImg);
        return 0;
    }
    memset(pImg->pImg, 0xFF, (((w + 31) >> 5) << 2) * h);
    return pImg;
}

void FreeImage(imgInfo *pInfo)
{
    if(pInfo && pInfo->pImg)
        free(pInfo->pImg);
    if(pInfo)
        free(pInfo);
}

int saveBMP(const imgInfo *pInfo, const char *fname)
{
    int lineBytes = (int) pInfo->line_bytes;
    int imgSize = lineBytes * pInfo->height;
    int lookUpSize = 256 * sizeof(uint32_t);
    bmpHdr bmpHead =
            {
                    0x4D42,                // unsigned short bfType;
                    sizeof(bmpHdr) + lookUpSize + imgSize,        // unsigned long  bfSize;
                    0, 0,                // unsigned short bfReserved1, bfReserved2;
                    sizeof(bmpHdr) + lookUpSize,    // unsigned long  bfOffBits;
                    40,                            // unsigned long  biSize;
                    (int32_t) pInfo->width,        // long  biWidth;
                    (int32_t) pInfo->height,        // long  biHeight;
                    1,                    // short biPlanes;
                    8,                    // short biBitCount;
                    0,                    // unsigned long  biCompression;
                    (uint32_t) imgSize, // unsigned long  biSizeImage;
                    11811,                // long biXPelsPerMeter; = 300 dpi
                    11811,                // long biYPelsPerMeter;
                    0,                    // unsigned long  biClrUsed;
                    0,                    // unsigned long  biClrImportant;
            };

    uint32_t lookUpTable[256];
    FILE *fbmp;
    unsigned char *ptr;
    int y;

    if((fbmp = fopen(fname, "wb")) == 0)
        return -1;
    if(fwrite(&bmpHead, sizeof(bmpHdr), 1, fbmp) != 1)
    {
        fclose(fbmp);
        return -2;
    }

    // initialize lookup
    for(uint32_t idx = 0; idx < 256; ++idx)
        lookUpTable[idx] = (idx << 16) | (idx << 8) | idx;
    if(fwrite(lookUpTable, sizeof(uint32_t), 256, fbmp) != 256)
    {
        fclose(fbmp);
        return -3;
    }

    ptr = pInfo->pImg + lineBytes * (pInfo->height - 1);


    for(y = pInfo->height; y > 0; --y, ptr -= lineBytes)
        if(fwrite(ptr, sizeof(unsigned char), lineBytes, fbmp) != (size_t) lineBytes)
        {
            fclose(fbmp);
            return -4;
        }
    fclose(fbmp);
    return 0;
}

unsigned char getPixel(imgInfo *pInfo, unsigned int x, unsigned int y)
{
    if(x >= pInfo->width || y >= pInfo->height)
        return 0;
    // y - liczba wierszy poprzedzajacych aktualny!
    return pInfo->pImg[y * pInfo->line_bytes + x];
}

void setPixel(imgInfo *pInfo, unsigned int x,
              unsigned int y, unsigned char value)
{
    if(x >= pInfo->width || y >= pInfo->height)
        return;
    pInfo->pImg[y * pInfo->line_bytes + x] = value;
}

int main(int argc, char *argv[])
{
    if(sizeof(bmpHdr) != 54)
    {
        printf("Change compilation options so as bmpHdr struct size is 62 bytes. Current size is: %d.\n",
               sizeof(bmpHdr));
        return 1;
    }

    if(argc < 3)
    {
        printf("Usage:\n\t%s input_file_name output_file_name\n", argv[0]);
        return 2;
    }
    // zad_8.exe lena-512x512.bmp wynik.bmp

    imgInfo *pInfo = readBMP(argv[1]);
    if(pInfo == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 3;
    }

    // ready to process image!
    printf("Image size: %d x %d pixels.\n", pInfo->width, pInfo->height);

    // to see change let's draw a 50x50 rectangle @(100,100)
//    for (unsigned int y = 100; y < 150; ++y)
//        for (unsigned int x = 100; x < 150; ++x)
//            setPixel(pInfo, x, y, 128);

    // this version cuts small rectangle from original
    // Lena image
    unsigned int w = 50, h = 30;
    unsigned int org_x = 262, org_y = 262;
    imgInfo *smallImg = InitImage(w, h);
    if(smallImg == NULL)
    {
        printf("Error creating output image.\n");
        FreeImage(pInfo);
        return 4;
    }
    for(unsigned int y = 0; y < h; ++y)
        for(unsigned int x = 0; x < w; ++x)
        {
            unsigned char pixel = getPixel(pInfo, org_x + x, org_y + y);
            setPixel(smallImg, x, y, pixel);
        }


    if(saveBMP(pInfo, argv[2]) != 0)
    {
        printf("Error writing output file: %s\n", argv[2]);
        FreeImage(smallImg);
        FreeImage(pInfo);
        return 4;
    }

    FreeImage(smallImg);
    FreeImage(pInfo);

    return 0;
}

