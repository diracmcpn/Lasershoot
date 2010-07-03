#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <GL/gl.h>
#include <GL/glu.h>
#include "shape.h"

typedef struct Scene Scene;
struct Scene
{
    int height;
    int width;
};

typedef struct Wheel Wheel;
struct Wheel
{
    Circle circle;
    Circle line;
    Coord position;
    double rotationAngle; //degree
    double rotationVelocity; //angle/second
};

typedef struct Body Body;
struct Body
{
    Rectangle rectangle;
    Coord position;
};

typedef struct Head Head;
struct Head
{
    Circle circle;
    Coord position;
};

typedef struct Canon Canon;
struct Canon
{
    Rectangle rectangle;
    Coord position;
    double rotationAngle; //degree
    double rotationVelocity; //angle/second
    double minAngle;
    double maxAngle;
};

typedef struct Vehicle Vehicle;
struct Vehicle
{
    Body body;
    Wheel frontWheel;
    Wheel rearWheel;
    Head head;
    Canon canon;
    Coord position;
    double velocity;
    double minPos;
    double maxPos;
};

typedef struct Ground Ground;
struct Ground
{
    Line line;
    Coord position;
};

typedef struct Medium Medium;
struct Medium
{
    Rectangle rectangle;
    Coord position;
};

typedef struct Stand Stand;
struct Stand
{
    Rectangle rectangle;
    Coord position;
};

typedef struct Target Target;
struct Target
{
    Circle circle;
    Coord position;
};

void drawBody(Body *body);
void drawWheel(Wheel *wheel);
void drawHead(Head *head);
void drawCanon(Canon *canon);
void drawVehicle(Vehicle *vehicle);
void drawGround(Ground *ground);
void drawMedium(Medium *medium);
void drawStand(Stand *stand);
void drawTarget(Target *target);

#endif // SCENE_H_INCLUDED
