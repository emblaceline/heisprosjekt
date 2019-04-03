#include "elev.h"
#include <stdio.h>
#include "panel.h"
#include "door.h"

bool doorIsOpen;
int lastFloor;
int lastDir;

void start_up();

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    //elev_set_motor_direction(DIRN_UP);

    doorIsOpen = false;

    start_up();
    int floor = N_FLOORS; //utenfor etasjesignalene
    
    while(1){

        if(elev_get_floor_sensor_signal() >= 0){
            lastFloor = elev_get_floor_sensor_signal();
        }

        while(elev_get_stop_signal()==0){
            check_all_button();

            //kode for å legge inn i kø og shit her ?

            if (correct_floor(floor)){ 
                elev_set_motor_direction(DIRN_STOP);
                open_door();
            }

            if(doorIsOpen){
                close_door();
            }
        }

        if(elev_get_floor_sensor_signal() >=0 ){
            emergency();
            printf("out\n");
            //for (floor = 0; floor < N_FLOORS; floor++){
                //remove_from_queue(floor);
            //}
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