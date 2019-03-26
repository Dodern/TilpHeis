/*
* @file
* @brief Module for interfacing with the buttons on the elevator.
*/

#include "elev.h"

#ifndef BUTTONS_H
#define BUTTONS_H

/*
* @brief reads all buttons and returns the first one it finds that is pressed.
* @param[out] buttonMatrix Matrix of dimention N_floors,3 that has a 1 where the buttons have been pressed.
*                          Has the following format: 
*                          {{BUTTON_UP1, BUTTON_DOWN1, BUTTON_COMMAND1};...;{BUTTON_UPN_FLOORS, BUTTON_DOWNN_FLOORS, BUTTON_COMMANDN_FLOORS}}
*/
void Buttons__readButtons(int[N_FLOORS][3]);

/*
* @brief Returns true if stop button is pressed.
* @param[out] bool representing whether the stop button is pressed.
*/
int Buttons__readStopButton();

#endif