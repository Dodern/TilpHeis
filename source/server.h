/*
* @file
* @brief Server module for the elevator project. Handles orders, setting lights and turning on/off motor.
*/

#ifndef SERVER_H
#define SERVER_H

#include "ioHandler.h"
#include "motorController.h"
#include <unistd.h>
#include "serverComputations.h"
#include <stdio.h>

extern int stopHasOpenedDoor_;
extern int orders_[N_FLOORS*3][2];
extern int dir_;

/*
* @brief Init function for the server module. Initializes variables needed.
*/
int Server__init();

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