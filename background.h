#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <GL/gl.h>
#include <GL/glu.h>

typedef struct Ground Ground;
struct Ground
{
    double height;
};

typedef struct Scene Scene;
struct Scene
{
    int height;
    int width;
};

void drawGround(Scene *scene, Ground *ground); //Draw the ground

#endif // BACKGROUND_H_INCLUDED
