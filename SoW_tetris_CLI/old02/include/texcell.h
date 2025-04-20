/////////////////////////////////////////////////////////////////////////////////
// File:	texcell.h
// charset:	UTF-8
// Project:	SoW_tetris_CLI
// Author:	xtatrax
// Date:	2025/04/05
// Copyright (c) 2025 xtatrax
// All rights reserved.
//
//
//
// メモ :
//		0 : 　
//		1 : ■
//		2 : ■R
//		3 : ■G
//		4 : ■BG
//		5 : ■B
//		6 : ■Y
//		7 : ■M
//		8 : ■C

///////////////////////////////////////////////////////////////////////////////
#pragma once


//**************************************************************************
// type    : union TexcellStatus;
// file    : texcell.h
// Author  : xtatrax
// Purpose : 8byte テキストセルステータス
// Date    : 2025/04/05
//
// Note    : 
//      char status;
//      bool isLock : 1;
//      char type   : 4;
//      char color  : 3;
//**************************************************************************
union TexcellStatus{
	char status;
	bool isLock : 1;
	char type   : 3;
	char color  : 4;
};
enum TCType{
	// max 7
	empty  = 0b000,
	block  = 0b001,
	wall   = 0b010,
	flame  = 0b011,
	status = 0b100,
	mask   = 0b111,
};
enum FlameType{
	// max 15
	Default   = 0b0000,
	TL   = 0b0001, // ┏
	H    = 0b0011, // ━
	TR   = 0b0100, // ┓
	V    = 0b0101, // ┃
	BL   = 0b0101, // ┗
	BR   = 0b0110, // ┛
	// bold = 0b1000, // 太字フラグ
	mask = 0b1111,
};
enum Tetromino{
	// max 15
	Default = 0b0000,
	I       = 0b0001,
	O       = 0b0010,
	T       = 0b0011,
	L1      = 0b0100,
	L2      = 0b0101,
	S1      = 0b0110,
	S2      = 0b0111,
	mask    = 0b1111,
};
struct StatusPacket{
	char hour ;
	char min  ;
	char sec  ;
	long long score;
};
struct Texcell{
	// 文字列の定数化これでいいんだっけ？。。。
	inline static const wchar_t *Default    = L"　"           ; // 空白
	inline static const wchar_t *I          = L"\e[36m■\e[0m" ; // Cyan
	inline static const wchar_t *O          = L"\e[93m■\e[0m" ; // Bright Yellow
	inline static const wchar_t *T          = L"\e[95m■\e[0m" ; // Bright Magenta
	inline static const wchar_t *L1         = L"\e[92m■\e[0m" ; // Bright Green
	inline static const wchar_t *L2         = L"\e[32m■\e[0m" ; // Green
	inline static const wchar_t *S1         = L"\e[91m■\e[0m" ; // Bright Red
	inline static const wchar_t *S2         = L"\e[31m■\e[0m" ; // Red
	inline static const wchar_t *Wall       = L"\e[0m■\e[0m"  ; // 壁
	inline static const wchar_t *Flame_TL   = L"┌"            ; // 壁
	inline static const wchar_t *Flame_H    = L"─"  ; // 壁
	inline static const wchar_t *Flame_TR   = L"┐"  ; // 壁
	inline static const wchar_t *Flame_V    = L"│"  ; // 壁
	inline static const wchar_t *Flame_BL   = L"└"  ; // 壁
	inline static const wchar_t *Flame_BR   = L"┘"  ; // 壁
	inline static const wchar_t *TimeTitle  = L"\e[0mTime\e[0m"; // タイムタイトル
	inline static const wchar_t *Time       = L"\e[0m%02d:%02d:%02d\e[0m"  ; // タイム
	inline static const wchar_t *ScoreTitle = L"\e[0mScore \e[0m"; // スコアタイトル
	inline static const wchar_t *Score      = L"\e[0m%010d\e[0m" ; // スコア
	inline static const wchar_t* convTTM(Tetromino ttc){
		switch(ttc){
			case Tetromino::I:
				return I;
			break;
			case Tetromino::O:
				return O;
			break;
			case Tetromino::T:
				return T;
			break;
			case Tetromino::L1:
				return L1;
			break;
			case Tetromino::L2:
				return L2;
			break;
			case Tetromino::S1:
				return S1;
			break;
			case Tetromino::S2:
				return S2;
			break;
		}
		return Default ;
	};
	inline static const wchar_t* convTCC(TexcellStatus& tcs, StatusPacket& sp){
		TCType type = (TCType)(tcs.type & 0b1111);
		switch(type){
			case TCType::empty:
				return Default;
			break;
			case TCType::block:
				return convTTM((Tetromino)(tcs.color & Tetromino::mask));
				break;
			case TCType::wall:
				return Wall;
				break;
			/*/ 以下修正知る
			case TCType::time_title:
				return TimeTitle;
				break;
			case TCType::time:
				return Time;
				break;
			case TCType::score_title:
				return ScoreTitle;
				break;
			case TCType::score:
				return Score;
				break;
				/**/
			default:
				return Default;
				break;
		}
		return Default;
	};
};