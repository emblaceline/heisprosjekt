/**
* @file
* @brief Library for handeling the door and timer
*/

typedef int bool;
#define true 1;
#define false 0;

#define WAIT_TIME 3

extern bool doorIsOpen;

/**
* @brief Sets the timestamp to a given wait-time in the future, turns on the "door open"-light 
* and sets the global variable doorIsOpen to true. 
*/
void door_open_door();


/**
* @brief If the real time is more than the given timestamp: turns off the "door open"-light
* resets the timestamp to 0 and sets the globle varuable doorIsOpen to false.
*/
void door_close_door();


/**
* @brief Function for setting the endtime for the timer.
*
* @param[in] waitTime The length of wanted timer.
*
* @return The endtime for the timer (real time + how long the timer will wait).
*/
int door_set_timer(int waitTime);


/**
* @brief Checks if the timer is done.
*
* @param[in] doorStatus The time for which the timer is done.
*
* @return 0 if the time is not up, 1 if the timer is done.
*/
int door_check_time(int doorStatus);