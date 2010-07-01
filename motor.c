#include "motor.h"

void rotateCanon(Canon *canon, Sens sens)
{
    if (sens==DIRECT)
    {
        canon->rotationAngle += canon->rotationVelocity/FRAME_PER_SECOND;
        if (canon->rotationAngle>canon->maxAngle)
        {
            canon->rotationAngle = 85;
        }
    }
    else if (sens==INDIRECT)
    {
        canon->rotationAngle -= canon->rotationVelocity/FRAME_PER_SECOND;
        if (canon->rotationAngle<canon->minAngle)
        {
            canon->rotationAngle = 0;
        }
    }
}

void rotateWheel(Wheel *wheel, Sens sens)
{
    if (sens==DIRECT)
    {
        wheel->rotationAngle += wheel->rotationVelocity/FRAME_PER_SECOND;
    }
    else if (sens==INDIRECT)
    {
        wheel->rotationAngle -= wheel->rotationVelocity/FRAME_PER_SECOND;
    }
}

void translateVehicle(Vehicle *vehicle, Direction direction)
{
    if (direction==RIGHT)
    {
        vehicle->position->x += vehicle->velocity/FRAME_PER_SECOND;

        if (vehicle->position->x+vehicle->body->rectangle->length/2>800)
        {
            vehicle->position->x = 800-vehicle->body->rectangle->length/2;
        }
    }
    else if (direction==LEFT)
    {
        vehicle->position->x -= vehicle->velocity/FRAME_PER_SECOND;

        if (vehicle->position->x-vehicle->body->rectangle->length/2<0)
        {
            vehicle->position->x = 0+vehicle->body->rectangle->length/2;
        }
    }
}
