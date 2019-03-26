#include "unitTest.h"

void UnitTest__motorControllerUnitTest(){
    MotorController__setDir(1);
    MotorController__setMotorStatus(1);
}

void UnitTest__lightUnitTest(){
    Lights__setCurrentFloorLights(3);
    Lights__setDesiredFloorLights(BUTTON_CALL_UP, 1, 1);
    Lights__setDesiredFloorLights(BUTTON_COMMAND, 1, 1);
    Lights__setStopLight(1);
    Lights__setDesiredFloorLights(BUTTON_CALL_UP, 2, 1);
    Lights__setDesiredFloorLights(BUTTON_CALL_DOWN, 1,1);
}

void UnitTest__floorSensorUnitTest(){
     printf("etasje %d \n", FloorSensors__floorStatus());
}

void UnitTest__buttonsUnitTest(){
    int buttonMatrix[N_FLOORS][3];
    for(int floor = 0; floor < N_FLOORS; floor++){
        for (int buttonType = 0; buttonType < 3; buttonType++){
            buttonMatrix[floor][buttonType] = 0;
        }
    }
    Buttons__readButtons(buttonMatrix);
    
    printf("button_up0 \t = %d \n",        buttonMatrix[0][0]);
    printf("button_down0 \t = %d \n",      buttonMatrix[0][1]);
    printf("button_command0 \t = %d \n",   buttonMatrix[0][2]);
    printf("button_up1 \t = %d \n",        buttonMatrix[1][0]);
    printf("button_down1 \t = %d \n",      buttonMatrix[1][1]);
    printf("button_command1 \t = %d \n",   buttonMatrix[1][2]);
    printf("button_up2 \t = %d \n",        buttonMatrix[2][0]);
    printf("button_down2 \t = %d \n",      buttonMatrix[2][1]);
    printf("button_command2 \t = %d \n",   buttonMatrix[2][2]);
    printf("button_up3 \t = %d \n",        buttonMatrix[3][0]);
    printf("button_down3 \t = %d \n",      buttonMatrix[3][1]);
    printf("button_command3 \t = %d \n\n", buttonMatrix[3][2]);
}

void UnitTest__ioHandlerUnitTest(){
    IoHandler__getFloorStatus();
    printf("Last floor = %d \n", IoHandler__getLastFloor());
    printf("Current floor = %d \n", IoHandler__getCurrentFloor());
    int buttonMatrix[N_FLOORS][3];
    if (IoHandler__getButtonStatus(buttonMatrix)){
        printf("Stop button pressed!\n");
    }
    printf("button_up0 \t = %d \n",        buttonMatrix[0][0]);
    printf("button_down0 \t = %d \n",      buttonMatrix[0][1]);
    printf("button_command0 \t = %d \n",   buttonMatrix[0][2]);
    printf("button_up1 \t = %d \n",        buttonMatrix[1][0]);
    printf("button_down1 \t = %d \n",      buttonMatrix[1][1]);
    printf("button_command1 \t = %d \n",   buttonMatrix[1][2]);
    printf("button_up2 \t = %d \n",        buttonMatrix[2][0]);
    printf("button_down2 \t = %d \n",      buttonMatrix[2][1]);
    printf("button_command2 \t = %d \n",   buttonMatrix[2][2]);
    printf("button_up3 \t = %d \n",        buttonMatrix[3][0]);
    printf("button_down3 \t = %d \n",      buttonMatrix[3][1]);
    printf("button_command3 \t = %d \n\n", buttonMatrix[3][2]);

    IoHandler__setLight(LIGHT_DOOR, 1, 1);
}