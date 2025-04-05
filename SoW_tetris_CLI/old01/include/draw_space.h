//////////////////////////////////////////////////////////////////
// Project:	SoW_tetris_CLI
// File:	coor-sys.h
// Author:	xtatrax
// Date:	2025/03/01
// Copyright (c) 2025
// All rights reserved.

#pragma ones


#include "coor-sys.h"
namespace tlibcap{
	typedef std::vector<std::wstring> Texcell_t;
	typedef std::vector<std::vector<char>> CallsState_t;
	class Block {
		// テトリスブロックの状態とか
			CallsState_t getBaceBlock(char i_state){
				CallsState_t csBlockBace;
				switch(i_state){
					case 0:
						csBlockBace.resize(4);
						csBlockBace[0].resize(4);
						csBlockBace[1].resize(4);
						csBlockBace[2].resize(4);
						csBlockBace[3].resize(4);
						csBlockBace[0] = {0,1,0,0};
						csBlockBace[1] = {0,1,0,0};
						csBlockBace[2] = {0,1,0,0};
						csBlockBace[3] = {0,1,0,0};
						break;
					case 1:
						csBlockBace.resize(3);
						csBlockBace[0].resize(3);
						csBlockBace[1].resize(3);
						csBlockBace[2].resize(3);
						csBlockBace[0] = {2,0,0};
						csBlockBace[1] = {2,2,0};
						csBlockBace[2] = {0,2,0};
					break;
					case 2:
						csBlockBace.resize(3);
						csBlockBace[0].resize(3);
						csBlockBace[1].resize(3);
						csBlockBace[2].resize(3);
						csBlockBace[0] = {0,0,3};
						csBlockBace[1] = {0,3,3};
						csBlockBace[2] = {0,3,0};
					break;
					case 3:
						csBlockBace.resize(3);
						csBlockBace[0].resize(3);
						csBlockBace[1].resize(3);
						csBlockBace[2].resize(3);
						csBlockBace[0] = {0,0,0};
						csBlockBace[1] = {0,4,0};
						csBlockBace[2] = {4,4,4};
					break;
					case 4:
						csBlockBace.resize(2);
						csBlockBace[0].resize(2);
						csBlockBace[1].resize(2);
						csBlockBace[0] = {5,5};
						csBlockBace[1] = {5,5};
					break;
					case 5:
						csBlockBace.resize(3);
						csBlockBace[0].resize(3);
						csBlockBace[1].resize(3);
						csBlockBace[2].resize(3);
						csBlockBace[0] = {0,6,6};
						csBlockBace[1] = {0,6,0};
						csBlockBace[2] = {0,6,0};
					break;
					case 6:
						csBlockBace.resize(3);
						csBlockBace[0].resize(3);
						csBlockBace[1].resize(3);
						csBlockBace[2].resize(3);
						csBlockBace[0] = {7,7,0};
						csBlockBace[1] = {0,7,0};
						csBlockBace[2] = {0,7,0};
						break;
				}
				return csBlockBace;
			}
		public:
			int m_iX;
			int m_iY;
			char m_cBlockType;
			CallsState_t m_csBlockStr; //
			Block(Block const &other) {
				this->m_iX = other.m_iX;
				this->m_iY = other.m_iY;
				this->m_csBlockStr = other.m_csBlockStr;
			}
			Block(char m_cBlockType) {
				this->m_iX = 0;
				this->m_iY = 0;
				m_csBlockStr = getBaceBlock(m_cBlockType);
			}
	};
	class Field {
		public:
			Texcell_t m_tcFieldStr;
			std::vector<Block> m_vBlocks;
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
			inline World() : w(0), h(0) {}
			inline World(int w, int h) : w(w), h(h) {}
			inline World(Pos2D pos) : w(pos.x), h(pos.y) {}
			inline void init(int w, int h) ;
			inline void init(Pos2D pos) {init(pos.x,pos.y);}
			inline int getW() { return this->w; }
			inline int getH() { return this->h; }
			inline void setW(int w) { this->w = w; }
			inline void setH(int h) { this->h = h; }
			inline void setPos(int x, int y) { this->w = x; this->h = y; }
			inline void setPos(Pos2D pos) { this->w = pos.x; this->h = pos.y; }
			inline Pos2D getPos() { return Pos2D(this->w, this->h); }
			void update() ;
			void draw() ;
	};
}