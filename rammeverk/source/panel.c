#include "panel.h"
#include "elev.h"
#include "queue.h"
#include <stdio.h>
#include "door.h"


void check_all_button(){
	for (int floor=0; floor<N_FLOORS; floor++) {
		if (elev_get_button_signal(BUTTON_COMMAND,floor)) {
			set_queue_command(floor, elev_get_floor_sensor_signal());
			elev_set_button_lamp(BUTTON_COMMAND,floor,1);
		}

		if (floor!=N_FLOORS-1) {
			if (elev_get_button_signal(BUTTON_CALL_UP, floor)==1){
				set_queue_up(floor);
				elev_set_button_lamp(BUTTON_CALL_UP, floor, 1);
			}
		}
		if (floor != 0) {
			if (elev_get_button_signal(BUTTON_CALL_DOWN, floor)==1){
				set_queue_down(floor);
				elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 1);
			}
		}
	}
}

void emergency(){  
	elev_set_motor_direction(DIRN_STOP);
	elev_set_stop_lamp(1);
	turn_off_all_lights();

	for(int floor = 0; floor<N_FLOORS; floor++){ //sletter bestillinger 
		remove_from_queue(floor);
	}

	printf("start\n");
	if(elev_get_floor_sensor_signal>=0){
		while(elev_get_stop_signal()){
			open_door();
		}
	}
	elev_set_stop_lamp(0);
	printf("stopp\n");
}



void turn_off_all_lights(){
	for(int floor = 0; floor < N_FLOORS; floor ++){
		elev_set_button_lamp(BUTTON_COMMAND,floor,0);
	}
	for(int floor = 0; floor < N_FLOORS-1; floor++){
		elev_set_button_lamp(BUTTON_CALL_UP,floor,0);
		elev_set_button_lamp(BUTTON_CALL_DOWN,floor+1,0);

	}

}

bool correct_floor(int floor){
    if(elev_get_floor_sensor_signal() == floor) {
        return true;
    }
    return false;
}





















