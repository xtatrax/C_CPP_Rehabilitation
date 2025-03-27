#include <stdio.h>
#include <unistd.h>
#include "../include/system.h"
#include <string>


// linux  CSI beep
// ESC [ 10 ; (hz) ]
// ESC [ 11 ; (msec) ]

void main_loop() {
	std::string str="　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　¥n";
	/*
	for(char i =0 ; i < 101 ; i++){
		for(char j = 0 ; j < 50 ; j++){
			char ch = "";
			if( i == 100){
				
			}
			field[i][j]
		}
	}
	*/
	display_cls();

	sleep(5);
	display_resize(50, 50);

	bool is_loop = false;
	do{
		
		sleep(1);
	}while(is_loop);
}