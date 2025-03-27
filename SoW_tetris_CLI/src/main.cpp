#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "../include/system.h"
#include <string>

int main() {
    std::string str1 = "Hello";
    printf("%s",str1.c_str());
	getchar();
	return 0;

}