#ifndef BASIS_H_INCLUDED
#define BASIS_H_INCLUDED
#include <GL/gl.h>
#include <GL/glu.h>

//Coordinate in the basis
typedef struct Coord Coord;
struct Coord
{
    double x;
    double y;
};

void drawFrame(int scale); //Draw a frame


#endif // BASIS_H_INCLUDED
