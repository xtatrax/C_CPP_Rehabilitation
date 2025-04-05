#include <stdlib.h>
#include <stdio.h>
#include "../include/system.h"

void display_resize(int x, int y){
    printf("\e[8;%d;%dt\n", y, x);
    //printf("\e[8;%d;%dt\n");
}

void display_cls() {
	system("clear");
}