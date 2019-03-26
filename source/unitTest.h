/*
* @file
* @brief Module for unit testing of the elevator project. Contains one function for each module.
*/

#include "motorController.h"
#include "lights.h"
#include "floorSensors.h"
#include <stdio.h>

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

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

#endif