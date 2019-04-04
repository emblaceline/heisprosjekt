#include "elev.h"
#include <stdio.h>
#include "panel.h"
#include "door.h"
#include "queue.h"

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


    doorIsOpen = false;

    start_up();
    printf("been her\n");
    int floor = N_FLOORS; 
    
    while(1){

        if(elev_get_floor_sensor_signal() >= 0){ // brukes for å huske hvor heisen er ved stopp.
            lastFloor = elev_get_floor_sensor_signal();
        }

        if(elev_get_stop_signal()){
            elev_set_motor_direction(DIRN_STOP);
            break;
        }

        while(elev_get_stop_signal()==0){
            
            panel_check_all_button();
            
            if(get_next_order()!=-1){
                int temp;
                temp=panel_compare(get_next_order(),lastFloor);
                printf("%i\n", temp);
            }

            //kode for å legge inn i kø og shit her ?

            

            if (panel_correct_floor(floor) && (!doorIsOpen)){ 
                elev_set_motor_direction(DIRN_STOP);
                //door_open_door();
            }
            

            if(doorIsOpen){
                //door_close_door();
            }
        }

        if(elev_get_floor_sensor_signal() >=0 ){
            panel_emergency();
            queue_remove_all_orders();
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
    lastFloor = elev_get_floor_sensor_signal();
}