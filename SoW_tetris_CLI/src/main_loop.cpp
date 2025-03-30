#include <stdio.h>
#include <unistd.h>
#include "../include/system.h"
#include <string>
#include <chrono>
#include <thread>
#include <vector>
using namespace std::chrono ;
// linux  CSI beep
// ESC [ 10 ; (hz) ]
// ESC [ 11 ; (msec) ]
// isFlameUpdate(int fps){
//    static prv_time = getTime();
//    f=1/fps;
//    now_time=getTime();
//    if( f>(prv_time - now_time)){
//        return true;
//    }
//    return false;



bool isFrameUpdate(char fps) {
	static int count = 0;
	static system_clock::time_point prev = system_clock::now();
	static system_clock::time_point prev_sec = system_clock::now();
	
	// 現在時間
	system_clock::time_point now = system_clock::now();
	system_clock::duration dur = now - prev_sec;        // 要した時間を計算
	long long msec1 = duration_cast<milliseconds>(dur).count();
	if (1.0f < ((float)msec1 / 1000)) {
		//system("cls");
		//printf("%d fps\n", count);
		count = 0;
		prev_sec = now;
	}
	dur = now - prev;        // 要した時間を計算
	long long msec = duration_cast<milliseconds>(dur).count();
	if ((1.0f / fps) < ((float)msec / 1000)) {
		count++;
		prev = now;
		return 1;
	}
	return 0;
}

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

	bool is_loop = false;
	do{
		if (isFrameUpdate(15)) {
			printf("\033[0;0f");
			//world.update();
			//world.draw();
		}
		std::this_thread::sleep_for(microseconds(10));

	}while(is_loop);
}