//
// Created by fsemerar on 10/30/23.
//

#ifndef MY_PROJECT_MANDELBROT_H
#define MY_PROJECT_MANDELBROT_H

namespace fractal{

class Mandelbrot {

public:
    static const int MAX_ITERATIONS = 1000;

public:
    static int getIterations(double x, double y);

};

}

#endif //MY_PROJECT_MANDELBROT_H
