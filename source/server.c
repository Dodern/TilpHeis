#include "server.h"

int desiredDir_ = 0;
int stopHasOpenedDoor_ = 0;
int orders_[N_FLOORS*3][2];
int doorOpen_ = 0;
int desired_ = -1;
int hasStoppedAtFloor_ = 0;
int lastDir_ = 0;

int Server__init(){
    ServerComputations__clearOrders();
    int currentFloor = IoHandler__getCurrentFloor();
    int lastFloor = IoHandler__getLastFloor();
    if (currentFloor != lastFloor ){
        printf("Not in a floor, so driving down!\n");
        MotorController__setDir(-1);
        while (currentFloor != lastFloor ){
            currentFloor = IoHandler__getCurrentFloor();
            lastFloor = IoHandler__getLastFloor();
        }
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
    int lightMatrix[N_FLOORS][3];
    for (int i = 0; i < N_FLOORS; i++){
        for (int j = 0; j < 3; j++){
            lightMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < N_FLOORS*3; i++){
        if (orders_[i][0] != -1){
            int c = orders_[i][0];
            int r = orders_[i][1];
            lightMatrix[r][c] = 1;
        }
    }
    for (int i = 0; i < N_FLOORS; i++){
        for (int j = 0; j < 3; j++){
            if (!(j == 1 && i == 0) && !(j == 0 && i == N_FLOORS - 1)){
                IoHandler__setLight(j, i, lightMatrix[i][j]);
            }
        }
    }
    if (doorOpen_){
        IoHandler__setLight(LIGHT_DOOR, 0, 1);
    }
}


void Server__motorLoop(){
    ServerComputations__setDesired();
    if(ServerComputations__shouldWeStop() && !hasStoppedAtFloor_){
        hasStoppedAtFloor_ = 1;
        ServerComputations__stopAtFloor();
    }
    else if(IoHandler__getCurrentFloor() == -1){
        hasStoppedAtFloor_ = 0;
    }
    else if ((desiredDir_ == -1) && IoHandler__getCurrentFloor() == 0){
        ServerComputations__stopAtFloor();
        //if (orders_[0][0] != -1){
        //    ServerComputations__setDesired();
        //}
        //else{
        //    desiredDir_ = 0;
        //}
        desiredDir_ = -desiredDir_;
    }
    else if ((desiredDir_ == 1) && IoHandler__getCurrentFloor() == 3){
        ServerComputations__stopAtFloor();
        //if (orders_[0][0] != -1){
        //    desiredDir_ = -1;
        //}
        //else{
        //    desiredDir_ = 0;
        //}
        desiredDir_ = -desiredDir_;
    }    
}