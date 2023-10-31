//
// Created by fsemerar on 10/24/23.
//

#include <iostream>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace fractal;
using namespace std;

int main(){

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{0});

    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            double xFractal = (x - WIDTH/2 - 200) * 2./HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2./HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            histogram[iterations]++;

            uint8_t color = 256 * (double)iterations / Mandelbrot::MAX_ITERATIONS;

            color = color * color * color;

            bitmap.setPixel(x, y, 0, color, 0);
            if (color < min) min = color;
            if (color > max) max = color;
        }
    }

    bitmap.write("/Users/fsemerar/Downloads/test.bmp");
    cout << "Finished" << endl;

    return 0;
}
