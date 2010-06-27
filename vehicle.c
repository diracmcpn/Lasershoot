#include "vehicle.h"

void drawVehicle(double xPosition, double canonRotation, double wheelRotation)
{
    //body structure
    Rectangle body;
    body.length = 100;
    body.width = 30;
    //wheel structure
    Disk wheel;
    wheel.radius = 12;
    wheel.nbVertex = 50;
    wheel.portion = FULL;
    //wheel line structure
    Circle wheelLine;
    wheelLine.radius = 10;
    wheelLine.nbVertex = 50;
    wheelLine.portion = HALF;
    //head structure
    Disk head;
    head.radius = 18;
    head.nbVertex = 50;
    head.portion = HALF;
    //Canon structure
    Rectangle canon;
    canon.length = 50;
    canon.width = 10;

    //Movement
    glTranslated(xPosition,0,0);

    glPushMatrix();
    glColor3ub(0,127,255);
    drawRectangle(&body);//
    glPopMatrix();

    glPushMatrix();
    glTranslated(-body.length/2+wheel.radius,-body.width/2-wheel.radius,0);
    glRotated(wheelRotation,0,0,1); //Rotation of the wheel
    glColor3ub(102,255,0);
    drawDisk(&wheel);//
    glColor3ub(0,0,0);
    drawCircle(&wheelLine);
    glPopMatrix();

    glPushMatrix();
    glTranslated(body.length/2-wheel.radius,-body.width/2-wheel.radius,0);
    glRotated(wheelRotation,0,0,1); //Rotation of the wheel
    glColor3ub(102,255,0);
    drawDisk(&wheel);//
    glColor3ub(0,0,0);
    drawCircle(&wheelLine);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,body.width/2,0);
    glColor3ub(255,255,0);
    drawDisk(&head);//
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,body.width/2+head.radius/2,0);
    glRotated(canonRotation,0,0,1); //Rotation of the canon
    glTranslated(canon.length/2,0,0);
    glColor3ub(153,0,255);
    drawRectangle(&canon);
    glPopMatrix();
}
