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
namespace tlib {
	typedef std::vector<std::wstring> texcell_t;
	struct Pos2D {
		int x;
		int y;
		Pos2D(int x, int y) { this->x = x; this->y = y; }
		Pos2D(Pos2D const &other)  { this->x = other.x; this->y = other.y; }
		Pos2D() { this->x = 0; this->y = 0; }
	};
	//const texcell_t 
	class Block {
	public:
		int m_iX;
		int m_iY;
		texcell_t m_tcBlockStr;
		Block() {
			m_iX = 0;
			m_iY = 0;
			m_tcBlockStr.push_back(std::wstring(L"■"));
		}
	};
	class Field {
		public:
			texcell_t m_tcFieldStr;
			texcell_t m_tcBlocksStr;
			int m_iX;
			int m_iY;
			int m_iW;
			int m_iH;
			Field() : m_iX(0), m_iY(0), m_iW(0), m_iH(0) {}
			Field(int i_ix, int i_iy, int i_iw, int i_ih) { init(i_ix, i_iy, i_iw, i_ih); }
			void init(int i_ix, int i_iy, int i_iw, int i_ih) ;
			void update() ;
			void draw() ;
	};
	class World{
			int h;
			int w;
			texcell_t m_tcWorldStr;
			std::wstring m_wsDrawFlame;
		public:
			World() : w(0), h(0) {}
			World(int w, int h) : w(w), h(h) {}
			World(Pos2D pos) : w(pos.x), h(pos.y) {}
			void init(int w, int h) ;
			void init(Pos2D pos) {init(pos.x,pos.y);}
			int getW() { return this->w; }
			int getH() { return this->h; }
			void setW(int w) { this->w = w; }
			void setH(int h) { this->h = h; }
			void setPos(int x, int y) { this->w = x; this->h = y; }
			void setPos(Pos2D pos) { this->w = pos.x; this->h = pos.y; }
			Pos2D getPos() { return Pos2D(this->w, this->h); }
			void update() ;
			void draw() ;
	};

}