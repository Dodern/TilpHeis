#include "buttons.h"

void Buttons__readButtons(int buttonVector[N_FLOORS][3]){
    // Iterate through the floors and through the different button types, 
    // where the button types are int representing the following:
    // BUTTON_CALL_UP = 0,
    // BUTTON_CALL_DOWN = 1,
    // BUTTON_COMMAND = 2
    for(int floor = 0; floor < N_FLOORS; floor++){
        for (int buttonType = 0; buttonType < 3; buttonType++){
            if (!((buttonType == 1 && floor == 0) || (buttonType == 0 && floor == 3))){
                buttonVector[floor][buttonType] = elev_get_button_signal(buttonType, floor);
            } else {
            buttonVector[floor][buttonType] = 0;
            } // if
        } // for
    } // for 
}