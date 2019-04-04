/**
* @file
* @brief Library to check for orders, 
* handle stop-button functions and driving the elevator
*/


/**
* @brief Checks if any order buttons are pressed, and turns on light and adds them to the order queue
* if they are.
*/
void panel_check_all_button(int last_floor);


/**
* @brief Stops the elevator, stop button is on while pressed. If elevator is on a floor the door is opened while 
* stop button is pressed and three sec after it is released. Turns off all order buttons.
*/
void panel_emergency();


/**
* @brief Turns of all order buttons.
*/
void panel_turn_off_all_lights();

/**
* @brief Checks if the floor we are on is the same as the wanted floor from the order.
*
* @param floor The floor of the order
*
* @return true if elevator is on correct floor, if not false.
*/
_Bool panel_correct_floor(int floor);

//void panel_drive(int last_floor);
int panel_compare(int order, int last_floor);
void drive(int lastFloor);