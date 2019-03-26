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