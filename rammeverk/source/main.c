#include "elev.h"
#include <stdio.h>
#include "panel.h"

typedef int bool;
#define true 1;
#define false 0;

void start_up();

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    //elev_set_motor_direction(DIRN_UP);

    start_up();
    
    while (1) {

       // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        
        check_all_button();
        printf("Set lamp\n");


        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }
    
    return 0;
}

void start_up() {
    bool driving = false;

    if(elev_get_floor_sensor_signal() == -1){
        elev_set_motor_direction(DIRN_DOWN);
        driving = true;
        while(driving){
            if(elev_get_floor_sensor_signal() >= 0){
                elev_set_motor_direction(DIRN_STOP);
                driving=false;
            }
        }
    }

    elev_set_floor_indicator(elev_get_floor_sensor_signal());
}