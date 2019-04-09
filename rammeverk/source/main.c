#include "elev.h"
#include "mechanism.h"
#include "door.h"
#include "queue.h"
#include <stdio.h>

void start_up();

int lastFloor;

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");


    start_up();
    printf("been here\n");
    //int floor = N_FLOORS; 
    
    while(1){
        if(elev_get_floor_sensor_signal() != -1){ 
            lastFloor = elev_get_floor_sensor_signal();
        }
        while(elev_get_stop_signal()==0){

            if(elev_get_floor_sensor_signal() >= 0){ 
                lastFloor = elev_get_floor_sensor_signal();
                if (lastFloor!=-1)
                    elev_set_floor_indicator(lastFloor);
            }
            mechanism_check_all_button(lastFloor);
            mechanism_drive(lastFloor);
            if(elev_get_stop_signal()){
                elev_set_motor_direction(DIRN_STOP);
                break;
            }   
            /*
            if (mechanism_correct_floor(floor) && (!door_get_door_open())){ 
                elev_set_motor_direction(DIRN_STOP);
                door_open_door();
            }*/
            

            if(door_get_door_open()){
                door_close_door();
            }
        }
        mechanism_emergency();
        queue_remove_all_orders();     
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
    lastFloor = elev_get_floor_sensor_signal();
}