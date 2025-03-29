////////////////////////////// //////////////////////////////
//	�v���W�F�N�g	�FVC17_tetris_CLI
//	�t�@�C����		�FTempus.h
//	�J����		�FMSVC++ 2022
//	�œK�^�u��		�F4
//	�S����			�Fxtatrax
//	�����ް��Ɣ��l	�F���Ԋ֌W�̊֐�
//					��
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
