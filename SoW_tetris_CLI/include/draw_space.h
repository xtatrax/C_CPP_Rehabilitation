/////////////////////////////////////////////////////////////////////////////////
// File    :  draw_space.h
// charset :  UTF-8
// Project :  SoW_tetris_CLI
// Author  :  xtatrax
// Date    :  2025/04/05
// Copyright (c) 2025 xtatrax
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////


#pragma once
#include <vector>
#include <string>
#include "coor_sys.h"
#include "texcell.h"
namespace tlibcap{
	//typedef std::vector<std::wstring> Texcell_t;

	// 操作方法
	// World
	// + Field
	//    + テトリスField
	//       + テトリスBlock
	// + Field
	//    + タイムField
	//       + タイムテキスト
	//       + mm:dd
	// + Field
	//    + スコアField
	//       + スコアテキスト
	//       + SSSSSSSSS
	//


	typedef std::vector<std::vector<TexcellStatus>> CallsState_t;
	class World;
	class Field;
	class Block;
	class DrawObject{
		Point m_pos;
		Size m_size;
		std::vector<DrawObject*> m_children;
		public:
			DrawObject(int width, int height) : m_size(width, height), m_pos(0, 0) {}
			DrawObject(int width, int height, int x, int y) : m_size(width, height), m_pos(x, y) {}
			DrawObject(int width, int height, const Point& pos) : m_size(width, height), m_pos(pos) {}
			DrawObject(const Size& size, int x, int y) : m_size(size), m_pos(x, y) {}
			DrawObject(const Size& size, const Point& pos) : m_size(size), m_pos(pos) {}
			~DrawObject(){}
			void update(CallsState_t& callsState) {
				int childSize = m_children.size();
				for(int i = 0; i < childSize; ++i)
					m_children[i]->update(callsState); // update children
			}
	};
	class Block : public DrawObject{
		public:
			Block(int width, int height) : DrawObject(width, height) {}
			Block(int width, int height, int x, int y) : DrawObject(width, height, x, y) {}
			Block(int width, int height, const Point& pos) : DrawObject(width, height, pos) {}
			Block(const Size& size, int x, int y) : DrawObject(size, x, y) {}
			Block(const Size& size, const Point& pos) : DrawObject(size, pos) {}
			~Block(){}
			void update(CallsState_t& callsState) {
				DrawObject::update(callsState);
			}
	};
	class Field : public DrawObject{
		protected:
			CallsState_t m_cells;
		public:
			Field(int width, int height) : DrawObject(width, height) {}
			Field(int width, int height, int x, int y) : DrawObject(width, height, x, y) {}
			Field(int width, int height, const Point& pos) : DrawObject(width, height, pos) {}
			Field(const Size& size, int x, int y) : DrawObject(size, x, y) {}
			Field(const Size& size, const Point& pos) : DrawObject(size, pos) {}
			~Field(){
				for(int i = 0; i < m_cells.size(); ++i){
					m_cells[i].clear();
				}
				m_cells.clear();
			}
	};
	class TetrisField : public Field{
		public:
			TetrisField(const Size& size, const Point& pos) ;
			TetrisField(int width, int height) : TetrisField( Size(width, height), Point(0, 0)) {}
			TetrisField(int width, int height, int x, int y) : TetrisField( Size(width, height), Point(x, y)) {}
			TetrisField(int width, int height, const Point& pos) : TetrisField( Size(width, height), pos) {}
			TetrisField(const Size& size, int x, int y) : TetrisField( size, Point(x, y)) {}
			void update(CallsState_t& callsState);
	};
	class World{
		private:
			Size m_size;
			CallsState_t m_cells;
			std::wstring m_wsDrawFlame;
			std::vector<Field> m_fields;
			StatusPacket m_status;
		public:
			World(int width, int height) ;
			std::wstring& calcTexcell();
			void update();
			~World();
	};
} // namespace tlibcap