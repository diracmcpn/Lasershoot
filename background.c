#include "background.h"

void drawGround(Scene *scene, Ground *ground)
{
    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2i(0,ground->height);
    glVertex2i(scene->width,ground->height);
    glEnd();
    glPopMatrix();
}
