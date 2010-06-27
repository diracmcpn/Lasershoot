#include "background.h"

void drawGround()
{
    glPushMatrix();
    glBegin(GL_LINE);
    glVertex2d(0,100);
    glVertex2d(800,1);
    glEnd();
    glPopMatrix();
}
