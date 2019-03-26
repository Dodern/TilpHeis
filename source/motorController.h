/**
* @file
* @brief Module that interfaces with the motor driver. It's only functions are setting the direction of the motor and making it start and stop.
*/

#include "motor.h"

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

void MotorController__setMotorStatus(int);

void MotorController__setDir(int);

#endif