/*
* @file
* @brief Helper module containing functions that the server needs.
*/
#ifndef SERVER_COMPUTATIONS_H
#define SERVER_COMPUTATIONS_H

#include "server.h"
#include "stdint.h"
#include "time.h"
#include "stdio.h"
#include <unistd.h>

/*
* @brief Simple for loop that clears the orders_ vector.
*/
void ServerComputations__clearOrders();

/*
* @brief Simple for loop that sets orders in orders_ vector by using buttons pressed and current floor.
*/
void ServerComputations__setOrders(int buttonMatrix[N_FLOORS][3], int currentFloor);

/*
* @brief Sets the desired floor for the elevator and starts going towards it.
*/
void ServerComputations__setDesired();

/*
* @brief Finds out if the elevator has to stop at a certain floor when passing it.
*/
int ServerComputations__shouldWeStop();

/*
* @brief Stops the elevator at the specified floor.
*/
void ServerComputations__stopAtFloor();


#endif