#include "panel.h"
#include "elev.h"
#include "queue.h"
#include <stdio.h>
#include "door.h"

static int motor_dir = DIRN_UP;

bool doorIsOpen;

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

void emergency(){  //slette bestillinger osv..
	elev_set_motor_direction(DIRN_STOP);
	elev_set_stop_lamp(1);
	if(elev_get_floor_sensor_signal>=0){
		while(elev_get_stop_signal()){
			open_door();
		}
	}
	elev_set_stop_lamp(0);
}


void drive(int current_floor, int current_direction){
	if(get_order_from_queue(current_floor, motor_dir) == 1){
		elev_set_motor_direction(motor_dir);
	}
	else if (get_order_from_queue(current_floor, -current_direction) == 1){
		motor_dir=-current_direction;
	}
	else{
		motor_dir=0;
	}
}




















