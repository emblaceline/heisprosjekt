#include "queue.h"
#include <stdio.h>
#include "elev.h"

static int up_queue[4]={0,0,0,0};
static int down_queue[4]={0};

void set_queue(int order, int lastFloor){
	if (order==lastFloor) {
		remove_from_queue(order);
	}
	else if (order>=lastFloor){
		up_queue[order]=1;
	}
	else if (order<=lastFloor){
		down_queue[order]=1;
	}
}

void set_up_queue(int order){
	up_queue[order]=1;
}

void set_down_queue(int order){
	down_queue[order]=1;
}

void remove_from_queue(int floor){
	up_queue[floor]=down_queue[floor]=0;
}

int queue_empty(){
	for(int i = 0; i<N_FLOORS; i++){
		if((up_queue[i]||down_queue[i])==1){
			return 0;
		}
	}
	return 1;
}

int get_next_order(int lastFloor){
	if(queue_empty()==1){
		return -2;
	}
	else{
		for (int i = 0; i < N_FLOORS; ++i)
			if(up_queue[i]==1){
				return i;
			}
		for (int j = 0; j < N_FLOORS; ++j)
		{
			if(down_queue[j]==1){
				return j;
			}
		}
	}
	return -2;
}


void queue_remove_all_orders(){
	for(int floor = 0; floor<N_FLOORS; floor++){  
		remove_from_queue(floor);
	}
}