#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <GL/gl.h>
#include <GL/glu.h>
#include "basis.h"


typedef struct Stand Stand;
struct Stand
{
    double width;
    double height;
    Coord *position;
};

void drawGround(Scene *scene, Ground *ground); //Draw the ground
void drawMedium(Medium *medium); //Draw the medium

#endif // BACKGROUND_H_INCLUDED
