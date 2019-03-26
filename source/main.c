#include "elev.h"
#include <stdio.h>
#include "motorController.h"
#include "unitTest.h"


int main() {
    int a = elev_init();
    if (!a){printf("Error initializing elev!\n");}
    
    while(1);

    return 0;
}
