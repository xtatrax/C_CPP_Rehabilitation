
#pragma once
#include "coor-sys.h"

float getNowTime();
float calcDiffTime(float start, float end);
void display_resize(int x, int y);
void display_cls();

tlib::Pos2D getCLIsize();