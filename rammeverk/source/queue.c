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

int is_queue_empty(){
	int i;
	int nr_order = 0;
	int temp;
	for(i=0; i<4;i++){
		if((up_queue[i]||down_queue[i])==1){
			nr_order++;
			temp=i;
		}
	}
	if(nr_order==1){//Kun en bestilling i heisen
 		return temp;
	}
	else if (nr_order>1){
 		return -2;
	}
	else{
		return -1;
	}
}