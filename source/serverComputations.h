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
void ServerComputations_clearOrders();

/*
* @brief Simple for loop that sets orders in orders_ vector by using buttons pressed and current floor.
*/
void ServerComputations_setOrders(int buttonMatrix[N_FLOORS][3], int currentFloor);

/*
* @brief Sets the desired floor for the elevator and starts going towards it.
*/
void ServerComputations_setDesired();

/*
* @brief Finds out if the elevator has to stop at a certain floor when passing it.
*/
int ServerComputations_shouldWeStop();

/*
* @brief Stops the elevator at the specified floor.
*/
void ServerComputations_stopAtFloor();


#endif