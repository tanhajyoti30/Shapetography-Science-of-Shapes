#ifndef RECTANGLE_
#define RECTANGLE_
#include "Shape.hpp"

class Rectangle : public Shape {

public:
    /* Parameterized constructor; takes in width and height, 
       iterates through the 2D array to populate it with 
       the necessary characters given the parameter dimensions */
    Rectangle(const int& width, const int& height);

    double getSurfaceArea();  //surface area
    double get3DVolume(const double &depth); // volume

};
#endif

