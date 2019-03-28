#include "panel.h"
#include "elev.h"

void check_all_button(){
	for (int floor=0; floor<N_FLOORS; floor++) {
		if (elev_get_button_signal(BUTTON_COMMAND,floor)) {
			elev_set_button_lamp(BUTTON_COMMAND,floor,1);
		}

		if (floor!=N_FLOORS-1) {
			if (elev_get_button_signal(BUTTON_CALL_UP, floor)==1){
				elev_set_button_lamp(BUTTON_CALL_UP, floor, 1);
			}
		}
		if (floor != 0) {
			if (elev_get_button_signal(BUTTON_CALL_DOWN, floor)==1){
				elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 1);
			}
		}
	}
}                                                     