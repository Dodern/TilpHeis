#include "ioHandler.h"

static int lastFloor_ = 0;
static int currentFloor_ = 0;





int IoHandler__getButtonStatus(int buttonMatrix[N_FLOORS][3]){
    Buttons__readButtons(buttonMatrix);
    return Buttons__readStopButton();
}