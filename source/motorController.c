#include "motorController.h"

void MotorController_setDir(int dir){
    // Set the direction of the motor.
    Motor_setDir(dir);
    // Tell it to run.
    Motor_startAndStopMotor(1);
}