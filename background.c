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

void drawMedium(Medium *medium)
{
    glPushMatrix();
    glColor3ub(0,245,255);
    glBegin(GL_LINE_LOOP);
    glVertex2d(medium->position->x-medium->width/2,medium->position->y-medium->height/2);
    glVertex2d(medium->position->x-medium->width/2,medium->position->y+medium->height/2);
    glVertex2d(medium->position->x+medium->width/2,medium->position->y+medium->height/2);
    glVertex2d(medium->position->x+medium->width/2,medium->position->y-medium->height/2);
    glEnd();
    glPopMatrix();
}
