#include "vehicle.h"

void drawBody(Body *body)
{
    glPushMatrix();
    glTranslated(body->position->x,body->position->y,0);
    glColor3ub(0,127,255);
    drawRectangle(body->rectangle);
    glPopMatrix();
}

void drawWheel(Wheel *wheel)
{
    glPushMatrix();
    glTranslated(wheel->position->x,wheel->position->y,0);
    glRotated(wheel->rotationAngle,0,0,1); //Rotation of the wheel
    glColor3ub(102,255,0);
    drawDisk(wheel->disk);//
    glColor3ub(0,0,0);
    drawCircle(wheel->wheelLine);
    glPopMatrix();
}

void drawHead(Head *head)
{
    glPushMatrix();
    glTranslated(head->position->x,head->position->y,0);
    glColor3ub(255,255,0);
    drawDisk(head->disk);
    glPopMatrix();
}

void drawCanon(Canon *canon)
{
    glPushMatrix();
    glTranslated(canon->position->x,canon->position->y,0);
    glRotated(canon->rotationAngle,0,0,1); //Rotation of the canon
    glTranslated(canon->rectangle->length/2,0,0);
    glColor3ub(153,0,255);
    drawRectangle(canon->rectangle);
    glPopMatrix();
}

void drawVehicle(Vehicle *vehicle)
{

    glPushMatrix();
    glTranslated(vehicle->position->x,vehicle->position->y,0);
    drawBody(vehicle->body);
    drawWheel(vehicle->frontWheel);
    drawWheel(vehicle->rearWheel);
    drawCanon(vehicle->canon);
    drawHead(vehicle->head);
    glPopMatrix();
}

void rotateCanon(Canon *canon, Sens sens)
{
    if (sens==DIRECT)
    {
        canon->rotationAngle += canon->rotationVelocity/FRAME_PER_SECOND;
        if (canon->rotationAngle>85)
        {
            canon->rotationAngle = 85;
        }
    }
    else if (sens==INDIRECT)
    {
        canon->rotationAngle -= canon->rotationVelocity/FRAME_PER_SECOND;
        if (canon->rotationAngle<0)
        {
            canon->rotationAngle = 0;
        }
    }
}
