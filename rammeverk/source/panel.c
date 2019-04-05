#include "panel.h"
#include "elev.h"
#include "queue.h"
#include <stdio.h>
#include "door.h"

int motorDirection;

void panel_check_all_button(int lastFloor){
	for (int floor=0; floor<N_FLOORS; floor++) {
		if (elev_get_button_signal(BUTTON_COMMAND,floor)) {
			set_queue(floor, lastFloor);
			elev_set_button_lamp(BUTTON_COMMAND,floor,1);
		}

		if (floor!=N_FLOORS-1) {

			if (elev_get_button_signal(BUTTON_CALL_UP, floor)==1){
				set_up_queue(floor);
				elev_set_button_lamp(BUTTON_CALL_UP, floor, 1);
			}
		}
		if (floor != 0) {
			if (elev_get_button_signal(BUTTON_CALL_DOWN, floor)==1){
				set_down_queue(floor);
				elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 1);
			}
		}
	}
}

void panel_emergency(){  
	elev_set_motor_direction(DIRN_STOP);
	elev_set_stop_lamp(1);
	panel_turn_off_all_lights();

	if(elev_get_floor_sensor_signal()>=0){
		while(elev_get_stop_signal()){
			door_open_door();
		}
	}
	elev_set_stop_lamp(0);
}



void panel_turn_off_all_lights(){
	for(int floor = 0; floor < N_FLOORS; floor ++){
		elev_set_button_lamp(BUTTON_COMMAND,floor,0);
	}
	for(int floor = 0; floor < N_FLOORS-1; floor++){
		elev_set_button_lamp(BUTTON_CALL_UP,floor,0);
		elev_set_button_lamp(BUTTON_CALL_DOWN,floor+1,0);

	}

}

void panel_turn_off_light(order){
	elev_set_button_lamp(BUTTON_COMMAND, order, 0);
	if (order<3){
		elev_set_button_lamp(BUTTON_CALL_UP, order, 0);
	}
	if (order>0){
		elev_set_button_lamp(BUTTON_CALL_DOWN, order, 0);
	}
}


_Bool panel_correct_floor(int floor){
    if(elev_get_floor_sensor_signal() == floor) {
        return true;
    }
    return false;
}

int panel_compare(int order, int last_floor){
	if(last_floor<order){
		return 1;
	}
	else if (last_floor>order){
		return -1;
	}
	else{
		return 0;
	}
}


void drive(int lastFloor){
    if(get_next_order(lastFloor)!=-2 && door_get_door_open()==0){
        int motor_dir;
        int order;
        int currentFloor;
        order=get_next_order(lastFloor);
        motor_dir = panel_compare(order,lastFloor);
        elev_set_motor_direction(motor_dir);
        currentFloor=elev_get_floor_sensor_signal();
        if(lastFloor==order ){
        	door_open_door();
        	remove_from_queue(order);
        	panel_turn_off_light(order);
        }

    }
}

int panel_button_pushed(int floor){
	if(elev_get_button_signal(BUTTON_COMMAND,floor)){
		return 1;
	}
	else if(elev_get_button_signal(BUTTON_CALL_DOWN,floor)){
		return 1;
	}
	else if(elev_get_button_signal(BUTTON_CALL_UP,floor)){
		return 1;
	}
	return 0;
}














