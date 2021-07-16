#include "Shape.hpp"
#include <iostream>
/** constructor  of shape*/
Shape::Shape(const int &width, const int &height) {
    this->displayChars = nullptr;
    this->width = width;
    this->height = height;
}
// the function that is  not given
void Shape::freeMemory() {
    if (displayChars!=nullptr) {
        for (int i=0; i<height; i++)
            delete[] displayChars[i];
        delete[] displayChars;
    }
}
// function that  is not given
char** Shape::reallocate(const int& height, const int& width) {
    char** nChars = new char*[height];
    for (int i=0; i<height; i++)
        nChars[i] = new char[width];
    return nChars;
}

Shape::~Shape() {/* creating  a destructor so the memory doesn't have leak*/
    freeMemory();
}
/**getter function*/
int Shape::getEdges() {
    return this->edges;
}

int Shape::getWidth() {
    return this->width;
}

int Shape::getHeight() {
    return this->height;
}

char** Shape::getDisplayChars() {
    return this->displayChars;
}
/**setter function*/
void Shape::setEdges(const int& edges) {
    this->edges = edges;
}

void Shape::setWidth(const int& new_width) {
    this->width = width;
}

void Shape::setHeight(const int &new_height) {
    this->height = height;
}

void Shape::setDisplayChars(char **display) {
    this->displayChars = display;
}
//rotate right function
void Shape::rotateRight() {
    int nWidth = height;
    int nHeight = width;

    char** nChars = reallocate(nHeight, nWidth);

    for (int i=0; i<width; i++)
        for (int j=0; j<height; j++)
            nChars[i][j] = displayChars[height-1-j][i];
/*setting to the new versions*/
    freeMemory();
    height = nHeight;
    width = nWidth;
    displayChars = nChars;
}
//rotate left function
void Shape::rotateLeft() {
    int nWidth = height;
    int nHeight = width;

    char** nChars = reallocate(nHeight, nWidth);

    for (int i=0; i<width; i++)
        for (int j=0; j<height; j++)
            nChars[i][j] = displayChars[j][width-i-1];
   /*setting to the newer version*/
    freeMemory();
    height = nHeight;
    width = nWidth;
    displayChars = nChars;
}
/*reflect function*/
void Shape::reflect(char axis) {
    if (axis=='x') {
        char* swapTemp;
/*have to  divide by 1/2*/
        for (int i=0; i<height/2; i++) {
            swapTemp = displayChars[i];
            displayChars[i] = displayChars[height-i-1];
            displayChars[height-i-1] = swapTemp;
        }
    } else if (axis=='y') {
        char swapTemp;

        for (int i=0; i<height; i++) {
            for (int j=0; j<width/2; j++) {/*if we divide by half if swaps*/
                swapTemp = displayChars[i][j];
                displayChars[i][j] = displayChars[i][width-j-1];
                displayChars[i][width-j-1] = swapTemp;
            }
        }
    }
}
//display
void Shape::display() {
    if (displayChars==nullptr)/*if  its nullptr return  nothing*/
        return;
        
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) 
            std::cout << displayChars[i][j] << ( j==width-1 ? "" : " ");/* if and else statement using ? and printing a space after a character but not after the width ends*/
        std::cout << '\n';
    }
}
