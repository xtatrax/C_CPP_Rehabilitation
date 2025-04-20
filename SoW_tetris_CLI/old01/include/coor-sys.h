/////////////////////////////////////////////////////////////////////////////////
// File:	coor-sys.h
// Project:	SoW_tetris_CLI
// Purpose:	Coordinate system for Tetris game
// Author:	xtatrax
// Date:	2025/03/01
// Copyright (c) 2025
// All rights reserved.
// 
#pragma ones
#include <string>
#include <vector>
namespace tlibccp {
	struct Pos2D {
		int x;
		int y;
		Pos2D(int x, int y) { this->x = x; this->y = y; }
		Pos2D(Pos2D const &other)  { this->x = other.x; this->y = other.y; }
		Pos2D() { this->x = 0; this->y = 0; }
	};
	//const texcell_t 

}