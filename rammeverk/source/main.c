#include "elev.h"
#include <stdio.h>
#include "panel.h"
#include "door.h"

bool doorIsOpen;

void start_up();
bool correct_floor(int floor);

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    //elev_set_motor_direction(DIRN_UP);

    bool doorIsOpen = false;

    start_up();
    int floor = 0;
    
    while(1){

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

        if(elev_get_floor_sensor_signal() == 1){
            emergency();
            //for (floor = 0; floor < N_FLOORS; floor++){
                //remove_from_queue(floor);
            //}
        }
        
    }

    
  
    /*while (1) {

       // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        
        check_all_button();
        drive(1,1);
        


        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }
    */
    
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

bool correct_floor(int floor){
    if(elev_get_floor_sensor_signal() == floor) {
        return true;
    }
    return false;
}