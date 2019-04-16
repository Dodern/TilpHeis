#include "elev.h"
#include <stdio.h>
#include "motorController.h"
#include "unitTest.h"
#include <unistd.h>
#include <time.h>
#include "server.h"


int main() {
    // initialize orders
    for (int i = 0; i < N_FLOORS*3; i++){
        orders_[i][0] = -1;
        orders_[i][1] = -1;
    }
    
    // initialize elevator driver
    int a = elev_init();
    if (!a){printf("Error initializing elev!\n");}
    else {printf("io initialized!\n");}
    
    // initialize server
    a = Server__init();
    if (!a){printf("Error initializing server!\n");}
    else {printf("Server intialized!\n");}

    // Endless loop.
    while(1){
        Server__buttonLoop();
        Server__lightLoop();
        Server__motorLoop();
    }
    return 0;
}
