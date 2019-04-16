#include "server.h"

int desiredDir_ = 0;
int stopHasOpenedDoor_ = 0;
int orders_[N_FLOORS*3][2];
int doorOpen_ = 0;
int desired_ = -1;
int hasStoppedAtFloor_ = 0;
int lastDir_ = 0;

int Server_init(){
    // Clear the orders.
    ServerComputations_clearOrders();
    int currentFloor = IoHandler_getCurrentFloor();
    int lastFloor = IoHandler_getLastFloor();
    // If not currently in a floor, drive down until we are.
    if (currentFloor != lastFloor ){
        printf("Not in a floor, so driving down!\n");
        MotorController_setDir(-1);
        while (currentFloor != lastFloor ){
            currentFloor = IoHandler_getCurrentFloor();
            lastFloor = IoHandler_getLastFloor();
        }
        // Stop when arriving at a floor.
        MotorController_setDir(0);
    }
    return 1;
}

void Server_buttonLoop(){
    int buttonMatrix[N_FLOORS][3]; 
    // Get buttonmatrix and possibly handle stop button press.
    while ((IoHandler_getButtonStatus(buttonMatrix))){
        IoHandler_setLight(LIGHT_STOP, 0, 1);
        MotorController_setDir(0);
        ServerComputations_clearOrders(); 
        if (IoHandler_getLastFloor() == IoHandler_getCurrentFloor()){
            IoHandler_setLight(LIGHT_DOOR, 0, 1);
        }
        stopHasOpenedDoor_ = 1;
    }
    // If stop was pressed, sleep for 3 seconds and set the appropiate lights.
    if (stopHasOpenedDoor_){
        IoHandler_setLight(LIGHT_STOP, 0, 0);
        sleep(3);
        IoHandler_setLight(LIGHT_DOOR, 0, 0);
        stopHasOpenedDoor_ = 0;
    }

    // use the button matrix and current floor to add and clear orders from orders_
    IoHandler_getButtonStatus(buttonMatrix);
    int currentFloor = IoHandler_getCurrentFloor();
    ServerComputations_setOrders(buttonMatrix, currentFloor);

}

void Server_lightLoop(){
    // clear all lights.
    int lightMatrix[N_FLOORS][3];
    for (int i = 0; i < N_FLOORS; i++){
        for (int j = 0; j < 3; j++){
            lightMatrix[i][j] = 0;
        }
    }
    // Set light matrix to match orders vector.
    for (int i = 0; i < N_FLOORS*3; i++){
        if (orders_[i][0] != -1){
            int c = orders_[i][0];
            int r = orders_[i][1];
            lightMatrix[r][c] = 1;
        }
    }
    // Set the lights by using the lightMatrix.
    for (int i = 0; i < N_FLOORS; i++){
        for (int j = 0; j < 3; j++){
            if (!(j == 1 && i == 0) && !(j == 0 && i == N_FLOORS - 1)){
                IoHandler_setLight(j, i, lightMatrix[i][j]);
            }
        }
    }
}


void Server_motorLoop(){
    // Find the desired floor and direction.
    ServerComputations_setDesired();
    // Figure out if we're currently at a floor and should stop.
    if(ServerComputations_shouldWeStop() && !hasStoppedAtFloor_){
        hasStoppedAtFloor_ = 1;
        // Stop the elevator.
        ServerComputations_stopAtFloor();
    }
    // If not at floor, reset the bool indicating we have.
    else if(IoHandler_getCurrentFloor() == -1){
        hasStoppedAtFloor_ = 0;
    }

    // Guard against driving past the lower and upper floors.
    else if ((desiredDir_ == -1) && IoHandler_getCurrentFloor() == 0){
        ServerComputations_stopAtFloor();
        desiredDir_ = -desiredDir_;
    }
    else if ((desiredDir_ == 1) && IoHandler_getCurrentFloor() == 3){
        ServerComputations_stopAtFloor();
        desiredDir_ = -desiredDir_;
    }    
}