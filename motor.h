#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
#include "vehicle.h"
#include "basis.h"
#define FRAME_PER_SECOND 40

void rotateCanon(Canon *canon, Sens sens);
void rotateWheel(Wheel *wheel, Sens sens);
/*
void translateVehicle(Vehicle *vehicle);*/
#endif // MOTOR_H_INCLUDED
