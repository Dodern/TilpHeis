#include "lights.h"

void Lights__setFloorLights(int floor){
    elev_set_floor_indicator(floor);
}
void Lights__setInsideLights(elev_button_type_t button, int floor, int value){
    elev_set_button_lamp(button, floor, value);
}
void Lights__setOutsideLights(elev_button_type_t button, int floor, int value){
    elev_set_button_lamp(button, floor, value);
}
void Lights__setDoorLight(int value){
    elev_set_door_open_lamp(value);
}
void Lights__setStopLight(int value){
    elev_set_stop_lamp(value);
}