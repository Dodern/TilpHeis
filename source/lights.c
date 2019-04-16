#include "lights.h"

void Lights_setCurrentFloorLights(int floor){
    elev_set_floor_indicator(floor);
}
void Lights_setDesiredFloorLights(elev_button_type_t button, int floor, int value){
    elev_set_button_lamp(button, floor, value);
}
void Lights_setDoorLight(int value){
    elev_set_door_open_lamp(value);
}
void Lights_setStopLight(int value){
    elev_set_stop_lamp(value);
}