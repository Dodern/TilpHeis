#include "motorController.h"

void MotorController__setDir(int dir){
    // Set the direction of the motor.
    Motor__setDir(dir);
    // Tell it to run.
    Motor__startAndStopMotor(1);
}