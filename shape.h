#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

typedef struct Coord Coord;
struct Coord
{
    double x;
    double y;
};

typedef struct Circle Circle;
struct Circle
{
    int nbVertex; //Number of vertex
    double radius; // Radius of the circle
    float piAngle; //Angle of the circle in Pi
    //center of the circle =(0,0)
};

typedef struct Rectangle Rectangle;
struct Rectangle
{
    double length;
    double width;
    //center of the rectangle = (0,0)
};

typedef struct Line Line;
struct Line
{
    double length;
    //center of the line = (0,0)
};

void drawFrame(int scale); //Draw a frame
void drawSolidCircle(Circle *circle); //Draw a solid circle
void drawBlankCircle(Circle *circle); //Draw a blank circle
void drawSolidRectangle(Rectangle *rectangle); //Draw a solid rectangle
void drawBlankRectangle(Rectangle *rectangle); //Draw a blank rectangle
void drawLine(Line *line); //Draw a line

#endif // SHAPE_H_INCLUDED
