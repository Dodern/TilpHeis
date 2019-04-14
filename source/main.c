#include "elev.h"
#include <stdio.h>
#include "motorController.h"
#include "unitTest.h"
#include <unistd.h>
#include <time.h>
#include "server.h"


int main() {
    for (int i = 0; i < N_FLOORS*3; i++){
        orders_[i][0] = -1;
        orders_[i][1] = -1;
    }
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
    int a = elev_init();
    if (!a){printf("Error initializing elev!\n");}
    else {printf("io initialized!\n");}

    a = Server__init();
    if (!a){printf("Error initializing server!\n");}
    else {printf("Server intialized!\n");}

    while(1){
        Server__buttonLoop();
        printf("Orders after:\n");
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
        printf("\n");
        Server__lightLoop();
        Server__motorLoop();
        //int ret = nsleep(1);
        //printf("sleep result %d\n",ret);
    }

    return 0;
}
