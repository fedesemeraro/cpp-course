//
// Created by fsemerar on 10/30/23.
//

#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace fractal{

int fractal::Mandelbrot::getIterations(double x, double y) {

    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;

    while (iterations < MAX_ITERATIONS){
        z = z*z + c;

        if (abs(z) > 2){
            break;
        }

        iterations++;
    }

    return iterations;
}

}
