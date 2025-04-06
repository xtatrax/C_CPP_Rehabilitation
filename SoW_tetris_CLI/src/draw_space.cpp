/////////////////////////////////////////////////////////////////
// File    : draw_space.cpp
// charset : UTF-8
// Project : SoW_tetris_CLI
// Author  : xtatrax
// Date    : 2025/03/01
// Copyright (c) 2025 xtatrax
// All rights reserved.
/////////////////////////////////////////////////////////////////

#include "../include/draw_space.h"


namespace tlibcap{

	TetrisField::TetrisField(const Size& size, const Point& pos)
	: Field(Size(size.height+1,size.width+2) , pos){
		m_cells.resize(size.height);
		for(int i = 0; i < size.height; ++i){
			m_cells[i].resize(size.width);
			for(int j = 0; j < size.width; ++j){
				m_cells[i][j].status = 0;
			}
		}
	}

	World::World(int width, int height) 
	: m_size(width, height)
	{
		m_status.hour = 0;
		m_status.min  = 0;
		m_status.sec  = 0;
		m_status.score = 0;
		m_cells.resize(height);
		for(int i = 0; i < height; ++i){
			m_cells[i].resize(width);
			for(int j = 0; j < width; ++j){
				m_cells[i][j].status = 0;
			}
		}
	}
	World::~World(){
		for(int i = 0; i < m_size.height; ++i){
			m_cells[i].clear();
		}
		m_cells.clear();
	}
	std::wstring& World::calcTexcell(){
		int h = m_cells.size();
		for(int i = 0; i < h; ++i){
			int w = m_cells[i].size();
			for(int j = 0; j < w; ++j){
				TexcellStatus& tcs = m_cells[i][j];
				m_wsDrawFlame += Texcell::convTCC( tcs, m_status);
			}
			m_wsDrawFlame += L"\n";
		}
	}
	void World::update(){
		int fieldSize = m_fields.size();
		for(int i = 0; i < fieldSize; ++i){
			m_fields[i].update(m_cells); // update children
		}
		World::calcTexcell();
	}
} // namespace tlibcap