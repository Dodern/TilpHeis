/**
* @file
* @brief Module that interfaces with the motor driver. It's only functions are setting the direction of the motor and making it start and stop.
*/

#include "motor.h"

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

/*
* @brief Sets the direction of the motor.
* @param[in] dir The desired direction; -1 means down, 1 means up, 0 means stand still.
*/
void MotorController_setDir(int);

#endif