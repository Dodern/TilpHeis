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
        for (int c = 0; c < 3; c ++){
            if (buttonMatrix[r][c]){
                if (r == 0){
                }
                int hasBeenSet = 0;
                int buttonPressHandled = 0;
                // if true then the button has been pressed, so go through orders_ looking for it.
                for (int i = 0; i < N_FLOORS*3; i++){
                    if (orders_[i][0] == c && orders_[i][1] == r){
                        hasBeenSet = 1;
                        if (r == 0){
                        }
                    }
                    else if(orders_[i][0] == -1 && !hasBeenSet && !buttonPressHandled){
                        if (r == 0){
                        }       
                        orders_[i][0] = c;
                        orders_[i][1] = r;
                        buttonPressHandled = 1;
                    }
                }
            }
        }

    }
    printf("Current floor = %d\n", currentFloor);
    for (int i = 0; i < N_FLOORS*3; i ++){
        if (orders_[i][1] == currentFloor){
            for (int j = i; j < N_FLOORS*3-1; j++){
                orders_[j][0] = orders_[j+1][0];
                orders_[j][1] = orders_[j+1][1];
            }
        }
    }
}