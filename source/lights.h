/**
* @file
* @brief Sets the status of the lights to on or off.
*/


#ifndef LIGHTS_H
#define LIGHTS_H

#include "elev.h"

/**
* @bried Sets the floor indicator lights.
* @param[in] floor The current floor of the elevator
*/
void Lights__setFloorLights(int floor);

/**
* @bried Sets the lights inside the elevator. 
* @param[in] button Type of button pressed (UP, DOWN or COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setInsideLights(elev_button_type_t button, int floor, int value);

/**
* @bried Sets the lights on each floor outside the elevator.
* @param[in] button Type of button pressed (UP, DOWN or COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setOutsideLights(elev_button_type_t button, int floor, int value);

/**
* @bried Sets the door indicator light.
* @param[in] button Type of button pressed (UP, DOWN or COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setDoorLight(int value);

/**
* @bried Sets the stop indicator light.
* @param[in] button Type of button pressed (UP, DOWN or COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setStopLight(int value);

#endif