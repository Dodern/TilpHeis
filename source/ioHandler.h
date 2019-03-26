/*
* @file 
* @brief Module that interfaces with the I/O on the elevator.
*/

#include "buttons.h"
#include "floorSensors.h"
#include "lights.h"

#ifndef IO_HANDLER_H
#define IO_HANDLER_H

/*
* @brief Private function that gets the floor status from the floor sensor and sets it in the internal variables currentFloor and lastFloor.
* @param[out] output The floor status. -1 means in between floor, other values reflect the floor it's in.
*/
int IoHandler__getFloorStatus();

/*
* @brief Returns vector of buttons pressed.
* @param[out] buttonMatrix Matrix of buttons pressed, in format:
*                    {{BUTTON_UP1, BUTTON_DOWN1, BUTTON_COMMAND1},..., {BUTTON_UPN_FLOORS, BUTTON_DOWNN_FLOORS, BUTTON_COMMANDN_FLOORS}}
* @param[out] output Returns -1 if stop button is pressed.
*/
int IoHandler__getButtonStatus(int[N_FLOORS][3]);

/*
* @brief Sets the light specified by the inputs.
* @param[in] button Type of light.
* @param[in] floor Floor of desired light.
* @param[in] value Turn light on or off. 0 for off, other values for on.
*/
void IoHandler__setLight(int, int, int);

/*
* @brief Returns the current floor, -1 means inbetween floors.
* @param[out] output Current floor.
*/
int IoHandler__getCurrentFloor();

/*
* @brief Returns the last floor the elevator was in.
* @param[out] output Last floor visited.
*/
int IoHandler__getLastFloor();

#endif