#include <stdio.h>
#include <unistd.h>
#include "../include/system.h"





void main_loop() {
	display_cls();

	sleep(5);
	display_resize(50, 50);

	bool is_loop = false;
	do{
		
		sleep(1);
	}while(is_loop);
}