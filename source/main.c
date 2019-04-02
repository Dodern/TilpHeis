#include "elev.h"
#include <stdio.h>
#include "motorController.h"
#include "unitTest.h"
#include <unistd.h>
#include <time.h>
#include "server.h"


int main() {
    int a = elev_init();
    if (!a){printf("Error initializing elev!\n");}

    
    
    while(1){
        UnitTest__buttonLoopUnitTest();        
        int ret = nsleep(500);
        printf("sleep result %d\n",ret);
    }

    return 0;
}
