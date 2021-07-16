#ifndef CIRCLE_
#define CIRCLE_
#include "Shape.hpp"

class Circle : public Shape {

public:
    //Parameterized contructor: takes diameter as width or height. 
    Circle(const int& diameter);

    double getSurfaceArea();                        
    double get3DVolume(const double& depth);

};
#endif

