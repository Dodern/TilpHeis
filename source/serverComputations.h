/*
* @file
* @brief Helper module containing functions that the server needs.
*/
#ifndef SERVER_COMPUTATIONS_H
#define SERVER_COMPUTATIONS_H

#include "server.h"

/*
* @brief Simple for loop that clears the orders_ vector.
*/
void ServerComputations__clearOrders();

/*
* @brief Simple for loop that sets orders in orders_ vector by using buttons pressed and current floor.
*/
void ServerComputations__setOrders(int buttonMatrix[N_FLOORS][3], int currentFloor);

#endif