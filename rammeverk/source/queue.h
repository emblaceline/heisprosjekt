/**
* @file
* @brief Library for doing operations on the 
* queue of orders
*/

void set_queue_command(int floor, int position);
void set_queue_up(int floor);
void set_queue_down(int floor);
void remove_from_queue(int floor);
int nr_of_orders();
int get_next_order();
void queue_remove_all_orders();