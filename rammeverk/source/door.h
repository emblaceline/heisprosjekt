#pragma once
typedef int bool;
#define true 1;
#define false 0;

#define WAIT_TIME 3

extern bool doorIsOpen;

void open_door();
void close_door();
int set_timer(int waitTime);
int check_time(int doorStatus);