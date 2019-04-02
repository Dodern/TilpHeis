#include "server.h"

int dir_ = 0;
int stopHasOpenedDoor_ = 0;
int orders_[N_FLOORS*3][2];

int Server__init(){
    ServerComputations__clearOrders();
    return 1;
}

void Server__buttonLoop(){
    int buttonMatrix[N_FLOORS][3]; 
    // Get buttonmatrix and possibly handle stop button press.
    while ((IoHandler__getButtonStatus(buttonMatrix))){
        printf("Stop button pressed!\n");
        IoHandler__setLight(LIGHT_STOP, 0, 1);
        MotorController__setMotorStatus(0);
        ServerComputations__clearOrders(); 
        if (IoHandler__getLastFloor() == IoHandler__getCurrentFloor()){
            IoHandler__setLight(LIGHT_DOOR, 0, 1);
            stopHasOpenedDoor_ = 1;
        }
    }
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

}

void Server__motorLoop(){
    
}