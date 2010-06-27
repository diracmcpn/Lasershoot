#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

typedef enum Portion Portion;
enum Portion
{
    FULL = 2, HALF = 1
};

typedef struct Disk Disk;
struct Disk
{
    double nbVertex; //Number of vertex
    double radius; // Radius of the disk
    Portion portion; //Portion of the disk
};

typedef struct Circle Circle;
struct Circle
{
    double nbVertex; //Number of vertex
    double radius; // Radius of the circle
    Portion portion; //Portion of the circle
};

typedef struct Rectangle Rectangle;
struct Rectangle
{
    double length;
    double width;
};

void drawDisk(Disk *disk); //Draw a disk
void drawCircle(Circle *circle); //Draw a circle
void drawRectangle(Rectangle *rectangle); //Draw a rectangle


#endif // SHAPE_H_INCLUDED
