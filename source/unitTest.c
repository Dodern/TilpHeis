#include "unitTest.h"

void UnitTest__motorControllerUnitTest(){
    MotorController__setDir(-1);
    MotorController__setMotorStatus(1);
}

void UnitTest__lightUnitTest(){
    Lights__setFloorLights(3);
    Lights__setInsideLights(BUTTON_CALL_UP, 1, 1);
    Lights__setInsideLights(BUTTON_COMMAND, 1, 1);
    Lights__setStopLight(1);
    Lights__setOutsideLights(BUTTON_CALL_UP, 2, 1);
    Lights__setOutsideLights(BUTTON_CALL_DOWN, 1,1);
}