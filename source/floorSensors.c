#include "floorSensors.h"

int FloorSensors__floorStatus(){
    return elev_get_floor_sensor_signal();
}
