#include "Rectangle.hpp"

Rectangle::Rectangle(const int& width, const int& height)
    : Shape(width, height)/* perameterized constructor and inheritence*/
{
    setEdges(4);/**4 sides */

    /** Populate 2D array with empty chars*/
    char **arr = new char *[getHeight()];
    for (int row = 0; row < getHeight(); row++)
    {
        arr[row] = new char[getWidth()];
        for (int col = 0; col < getWidth(); col++)
        {
            arr[row][col] = ' ';
        }
    }/**took it from circle cpp*/

    /* Populate the proper positions with *'s*/
    char ascii_counter = 48;

    for (int i=0; i<getHeight(); i++) {
        
        bool first_row = i==0;/* first row is w*/
        bool last_row = i==getHeight()-1;/* setting the last row*/
        
        /*first and last row should be the same but  the ascii chars will be different*/
        if(first_row || last_row) {
            for (int j=0; j<getWidth(); j++) {
                arr[i][j] = ascii_counter++;
                if (ascii_counter > 126)/**update the ascii*/
                    ascii_counter = 48;
            }
        }
        else {
            int first_col = 0;/* first columm*/
            int last_col = getWidth()-1;/* last column*/

            arr[i][first_col] = ascii_counter++;/*update the ascii*/
            if (ascii_counter > 126)
                ascii_counter = 48;
            
            bool last_col_is_empty = arr[i][last_col] == ' ';/*checks for the empty space*/
            if (last_col_is_empty) {
                arr[i][last_col] = ascii_counter++;/**update the ascii*/
                if (ascii_counter > 126)/**from the circle cpp*/
                    ascii_counter = 48;
            }
        }
    }

    setDisplayChars(arr);/**set the new display m*/
}
/*surface area is height * width*/
double Rectangle::getSurfaceArea() {
    return getHeight()*getWidth();
}
/*volume is height* width* depth*/
double Rectangle::get3DVolume(const double& depth) {
    return getSurfaceArea()*depth;
}
