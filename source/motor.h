/*
* @file
* @brief Low level motor driver. Sets the direction of the motor and starts and stops it.
*/

#ifndef MOTOR_H
#define MOTOR_H

#include "elev.h"

void Motor__startAndStopMotor(int);

void Motor__setDir(int);

#endif