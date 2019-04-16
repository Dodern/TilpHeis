#include "serverComputations.h"

void ServerComputations_clearOrders(){
    // Set all orders to be -1.
    for (int i = 0; i < N_FLOORS*3; i++){
        orders_[i][0] = -1;
        orders_[i][1] = -1;
    }
    desiredDir_ = 0;
}

void ServerComputations_setOrders(int buttonMatrix[N_FLOORS][3], int currentFloor){
    // For each pressed button in the button matrix, go through orders_ looking for the same, if not add to orders_
    for (int r = 0; r < N_FLOORS; r++){
        if (!(currentFloor == r)){
            for (int c = 0; c < 3; c++){
                if (buttonMatrix[r][c]){
                    int hasBeenSet = 0;
                    int buttonPressHandled = 0;
                    // if true then the button has been pressed, so go through orders_ looking for it.
                    for (int i = 0; i < N_FLOORS*3; i++){
                        if (orders_[i][0] == c && orders_[i][1] == r){
                            hasBeenSet = 1;
                        }
                        else if(orders_[i][0] == -1 && !hasBeenSet && !buttonPressHandled){
                            orders_[i][0] = c; // button type
                            orders_[i][1] = r; // floor
                            buttonPressHandled = 1;
                        }
                    }
                }
            }
        }

    }
    // If door is open, clear orders that are in the same floor.
    if (doorOpen_){
        doorOpen_ = 0;
        if (orders_[N_FLOORS*3-1][1] == currentFloor){
            orders_[N_FLOORS*3-1][0] = -1;
            orders_[N_FLOORS*3-1][1] = -1;
        }
        // When it has found an order in the same floor it moves the rest of the orders vector to the left, 
        // effectively writing over the order that was to be discarded.
        for (int i = N_FLOORS*3-2; i >= 0; i--){
            if (orders_[i][1] == currentFloor){
                for (int j = i; j < N_FLOORS*3-1; j++){
                    orders_[j][0] = orders_[j+1][0];
                    orders_[j][1] = orders_[j+1][1];
                }
            }
        }
    }
}

void ServerComputations_setDesired(){
    // check whether currently serving, if not get first order.
    int currentFloor = IoHandler_getCurrentFloor();
    if ((desiredDir_ == 0) &&(orders_[0][0] != -1) ){
        desired_ = orders_[0][1]; // desired floor.
        // Set desiredDir by taking the sign of desired - currentfloor. 
        // Unless stop button has been pressed, in which case desired = -1;
        if ((desired_ - currentFloor) > 0){
            desiredDir_ = 1;
        } 
        else if ((desired_ - currentFloor) < 0){
            desiredDir_ = -1;
        }
        else {
            desiredDir_ = 0;
        }
    }
    // Tell the motor to take the elevator in the desired direction.
    MotorController_setDir(desiredDir_);
}



int ServerComputations_shouldWeStop(){
    int currentFloor = IoHandler_getCurrentFloor();
    if (desired_ == currentFloor){
        return 1;
    }
    else if(currentFloor != -1){
        for (int i = 0; i < N_FLOORS*3; i++){
            if (orders_[i][1] == currentFloor){
                // check if there is an internal order in the floor, if so stop.
                if (orders_[i][0] == 2){
                    return 1;
                }
                // check if there are external orders going the same way as we are, if so stop.
                else if (((orders_[i][0] == 1) && (desiredDir_ == -1 ))){
                    return 1;
                }
                else if  ((orders_[i][0] == 0) && (desiredDir_ == 1)){
                    return 1;
                }
            }
        }
    } 
    return 0;    
}



void ServerComputations_stopAtFloor(){
    // Stop the elevator
    MotorController_setDir(0);
    if (IoHandler_getCurrentFloor() == desired_){
        desiredDir_ = 0;
    }
    // turn on door light
    IoHandler_setLight(LIGHT_DOOR, 0, 1);
    doorOpen_ = 1; // bool used by other parts of system
    // Microsleep for 3 sec, so we can add orders and lights while sleeping.
    for (int i = 0; i < 1000; i++){
        usleep(3000);
        Server_buttonLoop();
        Server_lightLoop();    
    }
    // turn of door light
    IoHandler_setLight(LIGHT_DOOR, 0, 0);
}