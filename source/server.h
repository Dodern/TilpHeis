/*
* @file
* @brief Server module for the elevator project. Handles orders, setting lights and turning on/off motor.
*/

#include "motorController.h"
#include "ioHandler.h"

#ifndef SERVER_H
#define SERVER_H

/*
* @brief Loop that handles new button presses, putting new orders into the order list.
*/
void Server__buttonLoop();

/*
* @brief Loop that handles setting the lights at appropriate times.
*/
void Server__lightLoop();

/*
* @brief Loop that handles setting the motor direction and turning on/off the motor too match our desired floor and stop button presses. 
* Also keeps the door open for 3 seconds when stopping at a floor.
*/
void Server__motorLoop();

#endif