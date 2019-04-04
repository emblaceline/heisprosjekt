#include "panel.h"
#include "elev.h"
#include "queue.h"
#include <stdio.h>
#include "door.h"


void panel_check_all_button(){
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

void panel_emergency(){  
	elev_set_motor_direction(DIRN_STOP);
	elev_set_stop_lamp(1);
	panel_turn_off_all_lights();

	printf("dør åpnet\n");
	if(elev_get_floor_sensor_signal>=0){
		while(elev_get_stop_signal()){
			//door_open_door();
		}
	}
	elev_set_stop_lamp(0);
	printf("stopp sluppet\n");
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


/*void panel_drive(int last_floor){
	bool driving = false;
	int order = get_next_order();
	int motor_dir = panel_compare(order,last_floor);
	elev_set_motor_direction(motor_dir);
	if (motor_dir!=0){
		driving=true;
		while(driving){
			if(panel_correct_floor(order)==1){
				elev_set_motor_direction(DIRN_STOP);
				driving=false;
			}
		}
	}
}*/

















