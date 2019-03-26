#include "elev.h"
#include <stdio.h>
#include "motorController.h"
#include "unitTest.h"


int main() {
    int a = elev_init();
    if (!a){printf("Error initializing elev!\n");}

    UnitTest__floorSensorUnitTest();
    
    while(1);

    return 0;
}
