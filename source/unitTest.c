#include "unitTest.h"

int nsleep(long miliseconds)
{
   struct timespec req, rem;

   if(miliseconds > 999)
   {   
        req.tv_sec = (int)(miliseconds / 1000);                            /* Must be Non-Negative */
        req.tv_nsec = (miliseconds - ((long)req.tv_sec * 1000)) * 1000000; /* Must be in range of 0 to 999999999 */
   }   
   else
   {   
        req.tv_sec = 0;                         /* Must be Non-Negative */
        req.tv_nsec = miliseconds * 1000000;    /* Must be in range of 0 to 999999999 */
   }   

   return nanosleep(&req , &rem);
}

void UnitTest__motorControllerUnitTest(){
    MotorController__setDir(1);
    MotorController__setMotorStatus(1);
}

void UnitTest__lightUnitTest(){
    Lights__setCurrentFloorLights(3);
    Lights__setDesiredFloorLights(BUTTON_CALL_UP, 1, 1);
    Lights__setDesiredFloorLights(BUTTON_COMMAND, 1, 1);
    Lights__setStopLight(1);
    Lights__setDesiredFloorLights(BUTTON_CALL_UP, 2, 1);
    Lights__setDesiredFloorLights(BUTTON_CALL_DOWN, 1,1);
}

void UnitTest__floorSensorUnitTest(){
     printf("etasje %d \n", FloorSensors__floorStatus());
}

void UnitTest__buttonsUnitTest(){
    int buttonMatrix[N_FLOORS][3];
    for(int floor = 0; floor < N_FLOORS; floor++){
        for (int buttonType = 0; buttonType < 3; buttonType++){
            buttonMatrix[floor][buttonType] = 0;
        }
    }
    Buttons__readButtons(buttonMatrix);
    
    printf("button_up0 \t = %d \n",        buttonMatrix[0][0]);
    printf("button_down0 \t = %d \n",      buttonMatrix[0][1]);
    printf("button_command0 \t = %d \n",   buttonMatrix[0][2]);
    printf("button_up1 \t = %d \n",        buttonMatrix[1][0]);
    printf("button_down1 \t = %d \n",      buttonMatrix[1][1]);
    printf("button_command1 \t = %d \n",   buttonMatrix[1][2]);
    printf("button_up2 \t = %d \n",        buttonMatrix[2][0]);
    printf("button_down2 \t = %d \n",      buttonMatrix[2][1]);
    printf("button_command2 \t = %d \n",   buttonMatrix[2][2]);
    printf("button_up3 \t = %d \n",        buttonMatrix[3][0]);
    printf("button_down3 \t = %d \n",      buttonMatrix[3][1]);
    printf("button_command3 \t = %d \n\n", buttonMatrix[3][2]);
}

void UnitTest__ioHandlerUnitTest(){
    IoHandler__getFloorStatus();
    printf("Last floor = %d \n", IoHandler__getLastFloor());
    printf("Current floor = %d \n", IoHandler__getCurrentFloor());
    int buttonMatrix[N_FLOORS][3];
    if (IoHandler__getButtonStatus(buttonMatrix)){
        printf("Stop button pressed!\n");
    }
    printf("button_up0 \t = %d \n",        buttonMatrix[0][0]);
    printf("button_down0 \t = %d \n",      buttonMatrix[0][1]);
    printf("button_command0 \t = %d \n",   buttonMatrix[0][2]);
    printf("button_up1 \t = %d \n",        buttonMatrix[1][0]);
    printf("button_down1 \t = %d \n",      buttonMatrix[1][1]);
    printf("button_command1 \t = %d \n",   buttonMatrix[1][2]);
    printf("button_up2 \t = %d \n",        buttonMatrix[2][0]);
    printf("button_down2 \t = %d \n",      buttonMatrix[2][1]);
    printf("button_command2 \t = %d \n",   buttonMatrix[2][2]);
    printf("button_up3 \t = %d \n",        buttonMatrix[3][0]);
    printf("button_down3 \t = %d \n",      buttonMatrix[3][1]);
    printf("button_command3 \t = %d \n\n", buttonMatrix[3][2]);

    IoHandler__setLight(LIGHT_DOOR, 1, 1);
}

void UnitTest__buttonLoopUnitTest(){
    int a = Server__init();
    if (!a){printf("Error initializing server!\n");}

    
    
    while(1){

        printf("Orders before:\n");
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
        int ret = nsleep(500);
        printf("%d\n",ret);
    }

}
