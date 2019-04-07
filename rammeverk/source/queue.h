/**
* @file
* @brief Library for doing operations on the 
* queue of orders
*/

/**
* @brief Puts the orders from the command-buttons into queue
*
* @param order What floor the order is at.
*
* @param lastFloor The last floor the elevator was registered at.
*/
void set_queue(int order, int lastFloor, int motor_dir);

/**
* @brief Removes an order from queue.
*
* @param floor The floor of the order.
*/
void remove_from_queue(int floor);

/**
* @brief Checks if there are any orders in queue.
*
* @return 1 if empty, 0 if there are any orders.
*/
int queue_empty();

/**
* @brief Gets the floor of the next order.
*
* @param lastFloor The floor the elevator was last registered at.
*
* @return Returns the floor of the next order. Returns -2 if there are no orders.
*/
int get_next_order_down(int lastFloor);

/**
* @brief Removes all orders in queue.
*/
void queue_remove_all_orders();

/**
* @brief Puts an order on the correct floor for a up-button.
*
* @param order The floor of the order.
*/
void set_up_queue(int order, int motor_dir);

/**
* @brief Puts an order on the correct floor for a down-button.
*
* @param order The floor of the order.
*/
void set_down_queue(int order, int motor_dir);

int get_next_order_up(int lastFloor);

void print_queue();

void choose_queue(int order, int motor_dir);

