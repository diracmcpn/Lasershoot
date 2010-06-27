#include "shape.h"

void drawDisk(Disk *disk)
{
    int i = 0;
    double x = 0;
    double y = 0;

    glBegin(GL_POLYGON);
    for (i=0;i<=disk->nbVertex; i++)
    {
        x = disk->radius*cos(i*disk->portion*3.14159/disk->nbVertex);
        y = disk->radius*sin(i*disk->portion*3.14159/disk->nbVertex);
        glVertex2f(x,y);
    }
    glEnd();
}

void drawCircle(Circle *circle)
{
    int i = 0;
    double x = 0;
    double y = 0;

    glBegin(GL_LINE_STRIP);
    for (i=0;i<=circle->nbVertex; i++)
    {
        x = circle->radius*cos(i*circle->portion*3.14159/circle->nbVertex);
        y = circle->radius*sin(i*circle->portion*3.14159/circle->nbVertex);
        glVertex2f(x,y);
    }
    glEnd();
}

void drawRectangle(Rectangle *rectangle)
{
    glBegin(GL_QUADS);
    glVertex2d(-rectangle->length/2,-rectangle->width/2);
    glVertex2d(-rectangle->length/2,rectangle->width/2);
    glVertex2d(rectangle->length/2,rectangle->width/2);
    glVertex2d(rectangle->length/2,-rectangle->width/2);
    glEnd();
}
