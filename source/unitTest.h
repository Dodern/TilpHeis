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
void UnitTest_motorControllerUnitTest();

/*
* @brief Unit test of the light module.
*/
void UnitTest_lightUnitTest();


/*
* @brief Unit test of the floorSensor module.
*/
void UnitTest_floorSensorUnitTest();

/*
* @brief Unit test of the buttons module
*/
void UnitTest_buttonsUnitTest();

/*
* @brief Unit test of the ioHandler module.
*/ 
void UnitTest_ioHandlerUnitTest();

/*
* @brief Unit test of buttonLoop in the server module.
*/
void UnitTest_buttonLoopUnitTest();

/*
* @brief Unit test of the lighLoop function in the server module.
*/
void UnitTest_lightLoopUnitTest();

#endif