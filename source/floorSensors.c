#include "floorSensors.h"

int FloorSensors__floorStatus(){
    elev_get_floor_sensor_signal();
}
