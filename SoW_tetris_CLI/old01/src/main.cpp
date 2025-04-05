#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "../include/system.h"
#include <string>
#include <chrono>

int main() {
	if(false){
		std::string str1 = "Hello\n";
		printf("%s",str1.c_str());
		auto start = std::chrono::system_clock::now();
		for( int i = 5 ; i > 0 ; i--){
			printf("count : %d\n",i);
			printf("sleep ret (%d)\n",sleep(1));
		}
		auto end = std::chrono::system_clock::now();
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		printf("msec (%f)",(float)msec/1000);

		display_cls();

		sleep(5);
		const char* teststr = "abcd";
		printf("test1 %s (%X)\n",teststr,teststr);
		//(*(teststr+1))=1;
		printf("test2 %s (%X)\n",teststr,teststr);
		(char&)(*teststr) = '0';
		printf("test3 %s (%X)\n",teststr,teststr);
	}
	display_resize(50, 50);
	
	getchar();
	return 0;

}