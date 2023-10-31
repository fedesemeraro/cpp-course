//
// Created by fsemerar on 10/30/23.
//

#ifndef MY_PROJECT_BITMAPFILEHEADER_H
#define MY_PROJECT_BITMAPFILEHEADER_H

#include <cstdint>
using namespace std;

namespace fractal {

#pragma pack(2)

struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

}

#endif //MY_PROJECT_BITMAPFILEHEADER_H
