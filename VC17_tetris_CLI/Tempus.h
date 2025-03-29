////////////////////////////// //////////////////////////////
//	プロジェクト	：VC17_tetris_CLI
//	ファイル名		：Tempus.h
//	開発環境		：MSVC++ 2022
//	最適タブ数		：4
//	担当者			：xtatrax
//	内包ﾃﾞｰﾀと備考	：時間関係の関数
//					▼
//	namespace tlib;
//		class Tempus ;
//		class Tempus2 ;
//

#pragma once
#include <chrono>
#include <thread>

namespace tlib {
	using namespace std::chrono;
	//using namespace std::chrono::system_clock;

	class Tempus
	{
		char m_chFlanmeLate;
		system_clock::time_point m_tpStartGameTime;
		unsigned int m_dwFrameAccumulator;
		system_clock::time_point m_tpPrevFlameTime;
		

		bool isFlameUpdate();

		void setFlameLate(char FlameLate) { m_chFlanmeLate = FlameLate; }
		char getFlameLate() { return m_chFlanmeLate; };

	};


}
