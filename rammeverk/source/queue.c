#include "queue.h"
#include <stdio.h>

static int up_queue[4]={0};
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

int queue_direction(int floor, int motor_dir){
	if (motor_dir==1){
		return up_queue[floor];
	}
	else if (motor_dir==-1){
		return down_queue[floor];
	}
	return 0;

}

int get_order_from_queue(int floor, int motor_dir){
	int i;
	int order;
	for (i = floor; (i>-1) && (i<4); i+=motor_dir){
		if(queue_direction(i,motor_dir)==1){
			order=1;
			break;
		}
		else{
			order=0;
		}
	}
	return order;
}