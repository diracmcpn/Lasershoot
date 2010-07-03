#include "shape.h"

void drawFrame(int scale)
{
    glPushMatrix();
    glScalef(scale,scale,scale);
    glBegin(GL_LINES);
    glColor3ub(0,0,255);
    glVertex2i(0,0);
    glVertex2i(1,0);
    glColor3ub(0,255,0);
    glVertex2i(0,0);
    glVertex2i(0,1);
    glEnd();
    glPopMatrix();
}

void drawSolidCircle(Circle *circle)
{
    int i = 0;
    double x = 0;
    double y = 0;

    glBegin(GL_POLYGON);
    for (i=0;i<=circle->nbVertex; i++)
    {
        x = circle->radius*cos(i*circle->piAngle*3.14159/circle->nbVertex);
        y = circle->radius*sin(i*circle->piAngle*3.14159/circle->nbVertex);
        glVertex2f(x,y);
    }
    glEnd();
}

void drawBlankCircle(Circle *circle)
{
    int i = 0;
    double x = 0;
    double y = 0;

    glBegin(GL_LINE_STRIP);
    for (i=0;i<=circle->nbVertex; i++)
    {
        x = circle->radius*cos(i*circle->piAngle*3.14159/circle->nbVertex);
        y = circle->radius*sin(i*circle->piAngle*3.14159/circle->nbVertex);
        glVertex2f(x,y);
    }
    glEnd();
}

void drawSolidRectangle(Rectangle *rectangle)
{
    glBegin(GL_QUADS);
    glVertex2d(-rectangle->length/2,-rectangle->width/2);
    glVertex2d(-rectangle->length/2,rectangle->width/2);
    glVertex2d(rectangle->length/2,rectangle->width/2);
    glVertex2d(rectangle->length/2,-rectangle->width/2);
    glEnd();
}

void drawBlankRectangle(Rectangle *rectangle)
{
    glBegin(GL_LINE_LOOP);
    glVertex2d(-rectangle->length/2,-rectangle->width/2);
    glVertex2d(-rectangle->length/2,rectangle->width/2);
    glVertex2d(rectangle->length/2,rectangle->width/2);
    glVertex2d(rectangle->length/2,-rectangle->width/2);
    glEnd();
}

void drawLine(Line *line)
{
    glBegin(GL_LINES);
    glVertex2i(-line->length/2,0);
    glVertex2i(line->length/2,0);
    glEnd();
}
