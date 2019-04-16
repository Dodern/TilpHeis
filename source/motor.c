#include "motor.h"

static int dir_ = 0; // -1 is down, 0 is stop, 1 is up.

/*
* @brief Starts and stops the motor using the motor driver in elev.h.
* @param[in] motorStatus Starts the motor if equal to 1, stops it if equal to 0.
*/
void Motor_startAndStopMotor(int motorStatus){
    if (motorStatus == 0){
        elev_set_motor_direction(0);
    } else {
        elev_set_motor_direction(dir_);
    }
}

/*
* @brief Sets the class variable dir_ to be equal to the input.
* @param[in] dir The direction you want to set for the motor. -1 is down, 0 is stop, 1 is up.
*/
void Motor_setDir(int dir){
    dir_ = dir;
}