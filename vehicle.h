#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED
#include "shape.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "basis.h"

typedef struct Wheel Wheel;
struct Wheel
{
    Disk *disk;
    Circle *wheelLine;
    Coord *position;
    double rotationAngle; //degree
    double rotationVelocity; //angle/second
};

typedef struct Body Body;
struct Body
{
    Rectangle *rectangle;
    Coord *position;
};

typedef struct Head Head;
struct Head
{
    Disk *disk;
    Coord *position;
};

typedef struct Canon Canon;
struct Canon
{
    Rectangle *rectangle;
    Coord *position;
    double rotationAngle; //degree
    double rotationVelocity; //angle/second
};

typedef struct Vehicle Vehicle;
struct Vehicle
{
    Body *body;
    Wheel *frontWheel;
    Wheel *rearWheel;
    Head *head;
    Canon *canon;
    Coord *position;
};

void drawBody(Body *body);
void drawWheel(Wheel *wheel);
void drawHead(Head *head);
void drawCanon(Canon *canon);
void drawVehicle(Vehicle *vehicle);

#endif // VEHICLE_H_INCLUDED
