/*
* @file
* @brief Module for unit testing of the elevator project. Contains one function for each module.
*/

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "motorController.h"
#include "lights.h"
#include "floorSensors.h"
#include <stdio.h>
#include "buttons.h"
#include "ioHandler.h"
#include "server.h"
#include <unistd.h>
#include <time.h>

/*
* @brief Function for sleeping in nanoseconds.
*/
int nsleep(long miliseconds);

/*
* @brief Unit test of the motorController module.
*/
void UnitTest__motorControllerUnitTest();

/*
* @brief Unit test of the light module.
*/
void UnitTest__lightUnitTest();


/*
* @brief Unit test of the floorSensor module.
*/
void UnitTest__floorSensorUnitTest();

/*
* @brief Unit test of the buttons module
*/
void UnitTest__buttonsUnitTest();

/*
* @brief Unit test of the ioHandler module.
*/ 
void UnitTest__ioHandlerUnitTest();

/*
* @brief Unit test of buttonLoop in the server module.
*/
void UnitTest__buttonLoopUnitTest();

/*
* @brief Unit test of the lighLoop function in the server module.
*/
void UnitTest__lightLoopUnitTest();

#endif