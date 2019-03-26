#include "motorController.h"

static int motorStatus_ = 0;

void MotorController__setMotorStatus(int motorStatus){
    motorStatus_ = motorStatus;
    Motor__startAndStopMotor(motorStatus);
}

void MotorController__setDir(int dir){
    Motor__setDir(dir);
}