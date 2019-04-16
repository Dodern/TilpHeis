#include "server.h"

int desiredDir_ = 0;
int stopHasOpenedDoor_ = 0;
int orders_[N_FLOORS*3][2];
int doorOpen_ = 0;
int desired_ = -1;
int hasStoppedAtFloor_ = 0;
int lastDir_ = 0;

int Server__init(){
    // Clear the orders.
    ServerComputations__clearOrders();
    int currentFloor = IoHandler__getCurrentFloor();
    int lastFloor = IoHandler__getLastFloor();
    // If not currently in a floor, drive down until we are.
    if (currentFloor != lastFloor ){
        printf("Not in a floor, so driving down!\n");
        MotorController__setDir(-1);
        while (currentFloor != lastFloor ){
            currentFloor = IoHandler__getCurrentFloor();
            lastFloor = IoHandler__getLastFloor();
        }
        // Stop when arriving at a floor.
        MotorController__setDir(0);
    }
    return 1;
}

void Server__buttonLoop(){
    int buttonMatrix[N_FLOORS][3]; 
    // Get buttonmatrix and possibly handle stop button press.
    while ((IoHandler__getButtonStatus(buttonMatrix))){
        IoHandler__setLight(LIGHT_STOP, 0, 1);
        MotorController__setDir(0);
        ServerComputations__clearOrders(); 
        desired_ = -1;
        if (IoHandler__getLastFloor() == IoHandler__getCurrentFloor()){
            IoHandler__setLight(LIGHT_DOOR, 0, 1);
        }
        stopHasOpenedDoor_ = 1;
    }
    // If stop was pressed, sleep for 3 seconds and set the appropiate lights.
    if (stopHasOpenedDoor_){
        sleep(3);
        IoHandler__setLight(LIGHT_DOOR, 0, 0);
        stopHasOpenedDoor_ = 0;
    }

    // use the button matrix and current floor to add and clear orders from orders_
    IoHandler__getButtonStatus(buttonMatrix);
    int currentFloor = IoHandler__getCurrentFloor();
    ServerComputations__setOrders(buttonMatrix, currentFloor);

}

void Server__lightLoop(){
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
                IoHandler__setLight(j, i, lightMatrix[i][j]);
            }
        }
    }
    // Also set the door light if door is open.
    if (doorOpen_){
        IoHandler__setLight(LIGHT_DOOR, 0, 1);
    }
}


void Server__motorLoop(){
    // Find the desired floor and direction.
    ServerComputations__setDesired();
    // Figure out if we're currently at a floor and should stop.
    if(ServerComputations__shouldWeStop() && !hasStoppedAtFloor_){
        hasStoppedAtFloor_ = 1;
        // Stop the elevator.
        ServerComputations__stopAtFloor();
    }
    // If we already have stopped, reset the bool indicating we have.
    else if(IoHandler__getCurrentFloor() == -1){
        hasStoppedAtFloor_ = 0;
    }

    // Guard against driving past the lower and upper floors.
    else if ((desiredDir_ == -1) && IoHandler__getCurrentFloor() == 0){
        ServerComputations__stopAtFloor();
        desiredDir_ = -desiredDir_;
    }
    else if ((desiredDir_ == 1) && IoHandler__getCurrentFloor() == 3){
        ServerComputations__stopAtFloor();
        desiredDir_ = -desiredDir_;
    }    
}