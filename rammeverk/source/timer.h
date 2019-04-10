#include <time.h>


/**
Starts timer
*/
void timer_start();

/**
@brief Tells if timer has exceeded three seconds
@returns 1 if timer has exceeded three seconds and 0 if not
*/
int timer_three_seconds();

/**
@brief Tells if timer is on
@returns 1 if timer is on and 0 if timer is turned off
*/
int is_timer_on();


/**
@brief Turns of timer. Sets the value of the timer variable to -1
*/
void turn_off_timer();