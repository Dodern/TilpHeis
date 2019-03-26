#include "lights.h"

void setFloorLights(int floor){
    elev_set_floor_indicator(floor);
}
void setInsideLights(elev_button_type_t button, int floor, int value){
    elev_set_button_lamp(button, floor, value);
}
void setOutsideLights(elev_button_type_t button, int floor, int value){
    elev_set_button_lamp(button, floor, value);
}
void setDoorLight(int value){
    elev_set_door_open_lamp(value);
}
void setStopLight(int value){
    elev_set_stop_lamp(value);
}