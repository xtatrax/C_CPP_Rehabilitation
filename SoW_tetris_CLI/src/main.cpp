#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "../include/system.h"
#include <string>
#include <chrono>

int main() {
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
	getchar();
	return 0;

}