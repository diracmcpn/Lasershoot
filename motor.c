#include "motor.h"

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
