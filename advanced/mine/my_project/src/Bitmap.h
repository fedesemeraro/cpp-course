//
// Created by fsemerar on 10/30/23.
//

#ifndef MY_PROJECT_BITMAP_H
#define MY_PROJECT_BITMAP_H

#include <string>
#include <cstdint>
using namespace std;

namespace fractal {

    class Bitmap {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr};

    public:
        Bitmap(int width, int height);

        bool write(string filename);

        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

        virtual ~Bitmap();
    };

}

#endif //MY_PROJECT_BITMAP_H
