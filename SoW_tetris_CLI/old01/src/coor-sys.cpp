/////////////////////////////////////////////////////////////////////////////////
// File:	coor-sys.cpp
// Project:	SoW_tetris_CLI
// Purpose:	Coordinate system
// Author:	xtatrax
// Date:	2025/03/01
// Copyright (c) 2025 
// All rights reserved.
//
#include "../include/coor-sys.h"

namespace tlibcap {
	void World::init(int w, int h) {
		this->w = w;
		this->h = h;
		for (int i = 0; i < h; i++) {
			std::wstring strline;
			for (int j = 0; j < w; j++) {
				strline.append(L"□");
			}
			strline.append(L"\n");
			m_tcWorldStr.push_back(strline);
		}
	}
	void World::update() {
		// update logic
	}
	void World::draw() {
		// draw logic
	}
}	