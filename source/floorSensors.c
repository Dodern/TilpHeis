#include "floorSensors.h"

int FloorSensors_floorStatus(){
    return elev_get_floor_sensor_signal();
}
