#include "motor.h"

void rotateCanon(Canon *canon, Sens sens)
{
    if (sens==DIRECT)
    {
        canon->rotationAngle += canon->rotationVelocity/FRAME_PER_SECOND;
        if (canon->rotationAngle>canon->maxAngle)
        {
            canon->rotationAngle = canon->maxAngle;
        }
    }
    else if (sens==INDIRECT)
    {
        canon->rotationAngle -= canon->rotationVelocity/FRAME_PER_SECOND;
        if (canon->rotationAngle<canon->minAngle)
        {
            canon->rotationAngle = canon->minAngle;
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

        if (vehicle->position->x>vehicle->maxPos)
        {
            vehicle->position->x = vehicle->maxPos;
        }
    }
    else if (direction==LEFT)
    {
        vehicle->position->x -= vehicle->velocity/FRAME_PER_SECOND;

        if (vehicle->position->x<vehicle->minPos)
        {
            vehicle->position->x = vehicle->minPos;
        }
    }
}
