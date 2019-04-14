#include "serverComputations.h"

void ServerComputations__clearOrders(){
    for (int i = 0; i < N_FLOORS*3; i++){
        orders_[i][0] = -1;
        orders_[i][1] = -1;
    }
    /*
    printf("Orders after init:\n");
    for (int i = 0; i < N_FLOORS*3; i++){
        if (orders_[i][0] == 0){
            printf("Order number %d = up, floor %d", i, orders_[i][1]+1);
        }
        if (orders_[i][0] == 1){
            printf("Order number %d = down, floor %d", i, orders_[i][1]+1);
        }
        if (orders_[i][0] == 2){
            printf("Order number %d = command, floor %d", i, orders_[i][1]+1);
        }
        if (orders_[i][0] == -1){
            printf("Order number %d does not exist", i);
        }
        printf("\n");
    }
    */
}

void ServerComputations__setOrders(int buttonMatrix[N_FLOORS][3], int currentFloor){
    // For each pressed button in the button matrix, go through orders_ looking for the same, if not add to orders_
    for (int r = 0; r < N_FLOORS; r++){
        if (!(currentFloor == r)){
            for (int c = 3; c < 0; c --){
                if (buttonMatrix[r][c]){
                    int hasBeenSet = 0;
                    int buttonPressHandled = 0;
                    // if true then the button has been pressed, so go through orders_ looking for it.
                    for (int i = 0; i < N_FLOORS*3; i++){
                        if (orders_[i][0] == c && orders_[i][1] == r){
                            hasBeenSet = 1;
                        }
                        else if(orders_[i][0] == -1 && !hasBeenSet && !buttonPressHandled){
                            orders_[i][0] = c;
                            orders_[i][1] = r;
                            buttonPressHandled = 1;
                        }
                    }
                }
            }
        }

    }
    //printf("Current floor = %d\n", currentFloor);
    //printf("doorOpen = %d!\n", doorOpen_);
    if (doorOpen_){
        doorOpen_ = 0;
        //printf("Door open, so trying to clear orders!\n");
        if (orders_[N_FLOORS*3-1][1] == currentFloor){
            orders_[N_FLOORS*3-1][0] = -1;
            orders_[N_FLOORS*3-1][1] = -1;
        }
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

void ServerComputations__setDesired(){
    // check whether currently serving, if not get first order
    int currentFloor = IoHandler__getCurrentFloor();
    //printf("desired = %d\n", desired_);
    if ((desiredDir_ == 0) &&(orders_[0][0] != -1) ){
        desired_ = orders_[0][1];
        printf("desired = %d\n", desired_);
        printf("current floor = %d\n", currentFloor);
        if ((desired_ - currentFloor) > 0){
            desiredDir_ = 1;
        } 
        else if ((desired_ - currentFloor) < 0){
            desiredDir_ = -1;
        }
    }
    //if (currentFloor == 0){
    //    if (orders_[0][0] != -1){
    //        desiredDir_ = 1;
    //    }
    //    else{
    //        desiredDir_ = 0;
    //    }
    //}
    //else if(currentFloor == 3){
    //    if (orders_[0][0] != -1){
    //        desiredDir_ = -1;
    //    }
    //    else{
    //        desiredDir_ = 0;
    //    }
    //}
    //printf("desiredDir_ = %d\n", desiredDir_);
    MotorController__setDir(desiredDir_);
}



int ServerComputations__shouldWeStop(){
    int currentFloor = IoHandler__getCurrentFloor();
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
                else if (((orders_[i][0] == 1) && (desiredDir_ = -1 )) || ((orders_[i][0] == 0) && (desiredDir_ = 1))){
                    return 1;
                }
            }
        }
    } 
    return 0;    
}



void ServerComputations__stopAtFloor(){
    MotorController__setDir(0);
    if (IoHandler__getCurrentFloor() == desired_){
        //desired_ = 0;
        desiredDir_ = 0;
    }
    IoHandler__setLight(LIGHT_DOOR, 0, 1);
    doorOpen_ = 1;
    //int waitPeriodInMillis = 90000;
    //clock_t startTime = clock();
    for (int i = 0; i < 1000; i++){
        usleep(3000);
        Server__buttonLoop();
        Server__lightLoop();    
    }
    //sleep(1);
    //Server__buttonLoop();
    //sleep(1);
    IoHandler__setLight(LIGHT_DOOR, 0, 0);
}