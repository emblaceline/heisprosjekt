#include <time.h>

int timer = -1;

void timer_start() {
	timer = time(NULL);
}

int timer_three_seconds(){
    if ((time(NULL)-timer)>2){
        return 1;
    }else{
        return 0;
    }
}

int is_timer_on(){
    if(timer != -1){
        return 1;
    }
    return 0;
}

void turn_off_timer(){
    timer = -1;
}