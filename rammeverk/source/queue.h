/**
* @file
* @brief Library for doing operations on the 
* queue of orders
*/

void set_queue_command(int floor, int position);
void set_queue_up(int floor);
void set_queue_down(int floor);
void remove_from_queue(int floor);
int is_queue_empty();
void queue_remove_all_orders();