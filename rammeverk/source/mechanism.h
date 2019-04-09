/**
* @file
* @brief Library to check for orders, 
* handle stop-button functions and driving the elevator
*/
#ifndef __INCLUDE_MECHANISM_H__
#define __INCLUDE_MECHANISM_H__

/**
* @brief Checks if any order buttons are pressed, and turns on light and adds them to the order queue
* if they are.
*/
void mechanism_check_all_button(int lastFoor);


/**
* @brief Stops the elevator, stop button is on while pressed. If elevator is on a floor the door is opened while 
* stop button is pressed and three sec after it is released. Turns off all order buttons.
*/
void mechanism_emergency();


/**
* @brief Turns off all order buttons.
*/
void mechanism_turn_off_all_lights();

void mechanism_turn_off_light(int order);

/**
* @brief Checks if the floor we are on is the same as the wanted floor from the order.
*
* @param floor The floor of the order
*
* @return true if elevator is on correct floor, if not false.
*/
_Bool mechanism_correct_floor(int order);

int mechanism_compare(int order, int lastFloor);

/**
* @brief Turns off call-up, call-down and command button on a floor.
*
* @param order Which floor to turn off the lights on.
*/

void mechanism_drive(int lastFloor);

#endif // #ifndef __INCLUDE_MECHANISM_H__