/**
* @file
* @brief Library for doing operations on the 
* queue of orders
*/

void set_queue(int order, int lastFloor);
void remove_from_queue(int floor);
int nr_of_orders();
int get_next_order(int lastFloor);
void queue_remove_all_orders();
void print_queue();