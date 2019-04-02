#include "ioHandler.h"

static int lastFloor_ = 0;
static int currentFloor_ = 0;



void IoHandler__getFloorStatus(){
	currentFloor_ = FloorSensors__floorStatus();
	if (currentFloor_ != -1){
		lastFloor_ = currentFloor_;
	}
}

int IoHandler__getButtonStatus(int buttonMatrix[N_FLOORS][3]){
    Buttons__readButtons(buttonMatrix);
    return Buttons__readStopButton();
}

void IoHandler__setLight(type_of_light_t light, int floor, int value){
    Lights__setCurrentFloorLights(lastFloor_);
    switch (light)
    {
        case LIGHT_CALL_UP:
            Lights__setDesiredFloorLights(0, floor, value);
            break;
        case LIGHT_CALL_DOWN:
            Lights__setDesiredFloorLights(1, floor, value);
            break;
        case LIGHT_COMMAND:
            Lights__setDesiredFloorLights(2, floor, value);
            break;
        case LIGHT_STOP:
            Lights__setStopLight(value);
            break;
        case LIGHT_DOOR:
            Lights__setDoorLight(value);
            break;
        default:
            break;
    }
}

int IoHandler__getCurrentFloor(){
    IoHandler__getFloorStatus();
    return currentFloor_;
}

int IoHandler__getLastFloor(){
    IoHandler__getFloorStatus();
    return lastFloor_;
}
