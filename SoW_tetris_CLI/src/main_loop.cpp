#include <stdio.h>
#include <unistd.h>
#include "../include/system.h"



// linux  CSI beep
// ESC [ 10 ; (hz) ]
// ESC [ 11 ; (msec) ]

void main_loop() {
	display_cls();

	sleep(5);
	display_resize(50, 50);

	bool is_loop = false;
	do{
		
		sleep(1);
	}while(is_loop);
}