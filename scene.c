#include "scene.h"

void drawBody(Body *body)
{
    glPushMatrix();
    glTranslated(body->position.x,body->position.y,0);
    glColor3ub(0,127,255);
    drawSolidRectangle(&(body->rectangle));
    glPopMatrix();
}

void drawWheel(Wheel *wheel)
{
    glPushMatrix();
    glTranslated(wheel->position.x,wheel->position.y,0);
    glRotated(wheel->rotationAngle,0,0,1);
    glColor3ub(102,255,0);
    drawSolidCircle(&(wheel->circle));
    glColor3ub(0,0,0);
    drawBlankCircle(&(wheel->line));
    glPopMatrix();
}

void drawHead(Head *head)
{
    glPushMatrix();
    glTranslated(head->position.x,head->position.y,0);
    glColor3ub(255,255,0);
    drawSolidCircle(&(head->circle));
    glPopMatrix();
}

void drawCanon(Canon *canon)
{
    glPushMatrix();
    glTranslated(canon->position.x,canon->position.y,0);
    glRotated(canon->rotationAngle,0,0,1); //Rotation of the canon
    glTranslated(canon->rectangle.length/2,0,0);
    glColor3ub(153,0,255);
    drawSolidRectangle(&(canon->rectangle));
    glPopMatrix();
}

void drawVehicle(Vehicle *vehicle)
{
    glPushMatrix();
    glTranslated(vehicle->position.x,vehicle->position.y,0);
    drawBody(&(vehicle->body));
    drawWheel(&(vehicle->frontWheel));
    drawWheel(&(vehicle->rearWheel));
    drawCanon(&(vehicle->canon));
    drawHead(&(vehicle->head));
    glPopMatrix();
}

void drawGround(Ground *ground)
{
    glPushMatrix();
    glTranslated(ground->position.x,ground->position.y,0);
    glColor3ub(255,255,255);
    drawLine(&(ground->line));
    glPopMatrix();
}

void drawMedium(Medium *medium)
{
    glPushMatrix();
    glTranslated(medium->position.x,medium->position.y,0);
    glColor3ub(0,245,255);
    drawBlankRectangle(&(medium->rectangle));
    glPopMatrix();
}

void drawStand(Stand *stand)
{
    glPushMatrix();
    glTranslated(stand->position.x,stand->position.y,0);
    glColor3ub(255,20,147);
    drawBlankRectangle(&(stand->rectangle));
    glPopMatrix();
}

void drawTarget(Target *target)
{
    glPushMatrix();
    glTranslated(target->position.x,target->position.y,0);
    glColor3ub(255,165,0);
    drawSolidCircle(&(target->circle));
    glPopMatrix();
}
