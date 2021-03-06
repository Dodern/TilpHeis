#include "server.h"

int dir_ = 0;
int stopHasOpenedDoor_ = 0;
int orders_[N_FLOORS*3][2];
static int doorOpen_ = 0;

int Server__init(){
    ServerComputations__clearOrders();
    return 1;
}

void Server__buttonLoop(){
    int buttonMatrix[N_FLOORS][3]; 
    // Get buttonmatrix and possibly handle stop button press.
    while ((IoHandler__getButtonStatus(buttonMatrix))){
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
    
}