/*
* @file
* @brief Low level motor driver. Sets the direction of the motor and starts and stops it.
*/

#include "elev.h"

#ifndef MOTOR_H
#define MOTOR_H

void Motor__startAndStopMotor(int);

void Motor__setDir(int);

#endif