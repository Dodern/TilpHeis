#include "elev.h"
#include <stdio.h>
#include "motorController.h"
#include "unitTest.h"
#include <unistd.h>


int main() {
    int a = elev_init();
    if (!a){printf("Error initializing elev!\n");}

    
    
    while(1){
        UnitTest__buttonsUnitTest();
        
        sleep(1);
    }

    return 0;
}
