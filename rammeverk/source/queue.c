#include "queue.h"
#include <stdio.h>
#include "elev.h"

static int up_queue[4]={0,0,0,0};
static int down_queue[4]={0};

void set_queue(int order, int lastFloor){
	if (order==lastFloor) {
		remove_from_queue(order);
	}
	else if (order>lastFloor){
		up_queue[order]=1;
	}
	else if (order<lastFloor){
		down_queue[order]=1;
	}
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

int get_next_order(int lastFloor){
	if(nr_of_orders()==0){
		return -2;
	}
	else if(nr_of_orders()>0){
		for (int i = lastFloor; i < N_FLOORS; ++i)
			if(up_queue[i]==1){
				return i;
			}
		for (int j = lastFloor; j > -1; --j)
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

void print_queue(){
	printf("up: ");
	for (int i = 0; i < N_FLOORS; ++i)
	{
		int temp=0;
		temp = up_queue[i];
		printf("%i", temp);
		if(i==3){
			printf("\n");
		}
	}
	printf("down: ");
	for (int i = 0; i < N_FLOORS; ++i)
	{
		int temp=0;
		temp = down_queue[i];
		printf("%i", temp);
		if(i==3){
			printf("\n");
		}
	}
}