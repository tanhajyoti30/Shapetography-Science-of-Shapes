#include "Triangle.hpp"

Triangle::Triangle(const int &side)/**parameterized constructor and inhetritence*/
    : Shape(side, side)
{
    setEdges(3);

    /**Populate 2D array with empty chars*/
    char **arr = new char *[getHeight()];
    for (int row = 0; row < getHeight(); row++)
    {
        arr[row] = new char[getWidth()];
        for (int col = 0; col < getWidth(); col++)
        {
            arr[row][col] = ' ';
        }
    }/** from the circle cpp**/

    /**Populate the proper positions with *'s**/
    char ascii_counter = 48;
    bool cell_is_empty;

    for (int i=0; i<getHeight(); i++) {
        arr[i][0] = ascii_counter++;
        // ascii has to  be 48 and 126
        if (ascii_counter > 126)
                ascii_counter = 48;

        bool last_row = i==getHeight()-1;/**has to be -1 because i  starts from 0**/
        if(last_row) {
            for(int j=1; j<i; j++) {
                cell_is_empty = arr[i][j]==' ';/**checckes for empty spots */
                if(cell_is_empty) {
                    arr[i][j] = ascii_counter++;
                    if (ascii_counter > 126)/**updates the ascii counter */
                        ascii_counter = 48;
                }
            }
        }
/**in order to create the diagonal make sure that*/
        cell_is_empty = arr[i][i] == ' ';/*checks for the empty sapce*/
        if (cell_is_empty) {
            arr[i][i] = ascii_counter++;
            if (ascii_counter > 126)/**updates the ascii*/
                ascii_counter = 48;
        }
    }

    setDisplayChars(arr);/**sets the display**/
}

double Triangle::getSurfaceArea(){/**1/2*base*height**/
    return 0.5*getHeight()*getWidth();
}
/*81/2*base*height* depth*/
double Triangle::get3DVolume(const double &depth){
    return getSurfaceArea()*depth;
}
