#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
#include "scene.h"
#define FRAME_PER_SECOND 40

typedef enum Direction Direction;
enum Direction
{
    RIGHT,LEFT,TOP,BOTTOM
};

typedef enum Sens Sens;
enum Sens
{
    DIRECT,INDIRECT
};

void rotateCanon(Canon *canon, Sens sens);
void rotateWheel(Wheel *wheel, Sens sens);
void translateVehicle(Vehicle *vehicle, Direction direction);

#endif // MOTOR_H_INCLUDED
