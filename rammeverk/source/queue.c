#include "queue.h"
#include <stdio.h>
#include "elev.h"
#include "door.h"

static int up_queue[4]={0,0,0,0};
static int down_queue[4]={0};

void set_queue(int order, int lastFloor, int motor_dir){
	elev_set_button_lamp(BUTTON_COMMAND, order,1);
	if (order==lastFloor) {
		if (elev_get_floor_sensor_signal()==order){ 
			door_open_door();
			elev_set_button_lamp(BUTTON_COMMAND,order,0);
		}
		else{
			choose_queue(order,motor_dir);
		}

	}
	else if (order>=lastFloor){
		up_queue[order]=1;
	}
	else if (order<=lastFloor){
		down_queue[order]=1;
	}
}

void choose_queue(int order, int motor_dir){
	if (motor_dir==1){
		down_queue[order]=1;
	}
	else {
		up_queue[order]=1;
	}
}

void set_up_queue(int order, int motor_dir){
	if (motor_dir==0){
		up_queue[order]=1;
	}
	else{
		choose_queue(order,motor_dir);
	}
}

void set_down_queue(int order, int motor_dir){
	if (motor_dir==0){
		down_queue[order]=1;
	}
	else{
		choose_queue(order,motor_dir);
	}
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

int get_next_order_up(int lastFloor){
	if(queue_empty()==1){
		return -2;
	}
	else{
		for (int i = lastFloor; i < N_FLOORS; i++){
			if(up_queue[i]==1){
				return i;
			}
		}
		for (int i = lastFloor; i >= 0; i--)
		{
			if(up_queue[i]==1){
				return i;
			}
		}
	}
	return -2;
}

int get_next_order_down(int lastFloor){
	if(queue_empty()==1){
		return -2;
	}
	else{
		for (int i = lastFloor; i >= 0; i--){
			if(down_queue[i]==1){
				return i;
			}
		}
		for (int i = lastFloor; i < N_FLOORS; i++)
		{
			if(down_queue[i]==1){
				return i;
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
	printf("UP: ");
	for (int i = 0; i < 4; ++i)
	{
		printf("%i", up_queue[i]);
		if(i==3){
			printf(" \n");
		}
	}
	printf("DOWN: ");
	for (int i = 0; i < 4; ++i)
	{
		printf("%i", down_queue[i]);
		if(i==3){
			printf(" \n");
		}
	}
}