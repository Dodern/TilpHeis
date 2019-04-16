#include "ioHandler.h"

static int lastFloor_ = 0;
static int currentFloor_ = 0;



void IoHandler_getFloorStatus(){
	currentFloor_ = FloorSensors_floorStatus();
	if (currentFloor_ != -1){
		lastFloor_ = currentFloor_;
	}
}

int IoHandler_getButtonStatus(int buttonMatrix[N_FLOORS][3]){
    Buttons_readButtons(buttonMatrix);
    return Buttons_readStopButton();
}

void IoHandler_setLight(type_of_light_t light, int floor, int value){
    Lights_setCurrentFloorLights(lastFloor_);
    switch (light)
    {
        case LIGHT_CALL_UP:
            Lights_setDesiredFloorLights(0, floor, value);
            break;
        case LIGHT_CALL_DOWN:
            Lights_setDesiredFloorLights(1, floor, value);
            break;
        case LIGHT_COMMAND:
            Lights_setDesiredFloorLights(2, floor, value);
            break;
        case LIGHT_STOP:
            Lights_setStopLight(value);
            break;
        case LIGHT_DOOR:
            Lights_setDoorLight(value);
            break;
        default:
            break;
    }
}

int IoHandler_getCurrentFloor(){
    IoHandler_getFloorStatus();
    return currentFloor_;
}

int IoHandler_getLastFloor(){
    IoHandler_getFloorStatus();
    return lastFloor_;
}
