#include "queue.h"
#include <stdio.h>
#include "elev.h"

static int up_queue[4]={0,0,0,0};
static int down_queue[4]={0};

void set_queue_command(int floor, int position){
	if (floor==position) {
		//open_door();
	}
	else if (floor>position){
		up_queue[floor]=1;
	}
	else if (floor<position){
		down_queue[floor]=1;
	}
}

void set_queue_up(int floor){
	up_queue[floor]=1;
}

void set_queue_down(int floor){
	down_queue[floor]=1;
}

void remove_from_queue(int floor){
	up_queue[floor]=down_queue[floor]=0;
}

int nr_of_orders(){
	int nr_order = 0;
	for(int i = 0; i<N_FLOORS; i++){
		if((up_queue[i]||down_queue[i])==1){
			nr_order++;
		}
	}
	return nr_order;
}

int get_next_order(){
	if(nr_of_orders()==0){
		return -1;
	}
	else if(nr_of_orders()==1){
		for (int i = 0; i < N_FLOORS; ++i)
		{
			if((up_queue[i]||down_queue[i])==1){
				return i;
			}
		}
	}
	return 100;
}


void queue_remove_all_orders(){
	for(int floor = 0; floor<N_FLOORS; floor++){  
		remove_from_queue(floor);
	}
}
