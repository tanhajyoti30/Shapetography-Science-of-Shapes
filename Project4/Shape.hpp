#ifndef SHAPE_
#define SHAPE_

class Shape {
    
public:
    // Parameterized Constructor; there is no default constructor
    Shape(const int &width, const int &height);
    ~Shape();

    // Getters
    int getEdges();
    int getWidth();
    int getHeight();
    char **getDisplayChars();
    
    // Setters
    void setEdges(const int& edges); 
    void setWidth(const int& new_width);
    void setHeight(const int &new_height);
    void setDisplayChars(char **display);

    // Mutators
    void rotateRight();         //rotate by 90 degrees
    void rotateLeft();          //rotate by 90 degrees
    void reflect(char axis);    //reflect over x or y axis
    
    // Pure Virtual Methods (no implementation)
    virtual double getSurfaceArea() = 0;                   
    virtual double get3DVolume(const double& depth) = 0;    

    // Display - //iterate through 2D array and print chars
    void display();

private:
    int height, width, edges;
    char **displayChars;

    void freeMemory();
    char** reallocate(const int& height, const int& width);
};
#endif
