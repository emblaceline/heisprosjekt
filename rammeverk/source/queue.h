/**
* @file
* @brief Library for doing operations on the 
* queue of orders
*/
#ifndef __INCLUDE_QUEUE_H__
#define __INCLUDE_QUEUE_H__

/**
* @brief Puts the orders from the command-buttons into queue
*
* @param order What floor the order is at.
*
*
* @param[in] lastFloor The last floor the elevator was registered at.
*
* @param[in] motorDir The direction of the elevator.
*/
void queue_set(int order, int lastFloor, int motorDir);

/**
* @brief Puts an order on the correct floor for a up-button.
*
* @param order The floor of the order.
*/
void queue_set_up_queue(int order, int lastFloor);


/**
* @brief Puts an order on the correct floor for a down-button.
*
* @param order The floor of the order.
*/
void queue_set_down_queue(int order, int lastFloor);

void queue_choose(int order, int motorDir);

/**
* @brief Removes an order from queue.
*
* @param floor The floor of the order.
*/
void queue_remove_element(int floor);

/**
* @brief Removes all orders in queue.
*/
void queue_remove_all_orders();

/**
* @brief Checks if there are any orders in queue.
*
* @return 1 if empty, 0 if there are any orders.
*/
int queue_empty();

int queue_get_next_order_up(int lastFloor);

/**
* @brief Gets the floor of the next order.
*
* @param lastFloor The floor the elevator was last registered at.
*
* @return Returns the floor of the next order. Returns -2 if there are no orders.
*/
int queue_get_next_order_down(int lastFloor);


void print_queue();



#endif // #ifndef __INCLUDE_QUEUE_H__
