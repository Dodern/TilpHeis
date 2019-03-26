/**
* @file
* @brief Sets the status of the lights to on or off.
*/


#ifndef LIGHTS_H
#define LIGHTS_H

#include "elev.h"

/**
* @brief Sets the floor indicator lights.
* @param[in] floor The current floor of the elevator
*/
void Lights__setFloorLights(int floor);

/**
* @brief Sets the lights inside the elevator. 
* @param[in] button Type of button pressed (BUTTON_CALL_UP, BUTTON_CALL_DOWN or BUTTON_COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setInsideLights(elev_button_type_t button, int floor, int value);

/**
* @brief Sets the lights on each floor outside the elevator.
* @param[in] button Type of button pressed (BUTTON_CALL_UP, BUTTON_CALL_DOWN or BUTTON_COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setOutsideLights(elev_button_type_t button, int floor, int value);

/**
* @brief Sets the door indicator light.
* @param[in] button Type of button pressed (BUTTON_CALL_UP, BUTTON_CALL_DOWN or BUTTON_COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setDoorLight(int value);

/**
* @brief Sets the stop indicator light.
* @param[in] button Type of button pressed (BUTTON_CALL_UP, BUTTON_CALL_DOWN or BUTTON_COMMAND)
* @param[in] floor The current floor of the elevator.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void Lights__setStopLight(int value);

#endif