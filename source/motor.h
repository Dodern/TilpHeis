/*
* @file
* @brief Low level motor driver. Sets the direction of the motor and starts and stops it.
*/

#include "elev.h"

#ifndef MOTOR_H
#define MOTOR_H

/*
* @brief Starts and stops the motor using the motor driver in elev.h.
* @param[in] motorStatus Starts the motor if equal to 1, stops it if equal to 0.
*/
void Motor__startAndStopMotor(int);

/*
* @brief Sets the class variable dir_ to be equal to the input.
* @param[in] dir The direction you want to set for the motor. -1 is down, 0 is stop, 1 is up.
*/
void Motor__setDir(int);

#endif