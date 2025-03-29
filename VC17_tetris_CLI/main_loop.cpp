#include <stdio.h>
// unix #include <unistd.h>
//#include <timeapi.h>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#pragma comment( lib, "winmm.lib" )
using namespace std::chrono ;
//using namespace std;


int getPushKey() {
	if (_kbhit()) {
		return tolower(_getch());
	}
	return 0;
}

class Block {
public:
	int m_iX;
	int m_iY;

	std::vector<std::wstring> m_vBlockStr;
	Block() {
		m_iX = 0;
		m_iY = 0;
		m_vBlockStr.push_back(std::wstring(L"■"));
	}
	
};

class World{
	std::vector<std::wstring> m_vWorldStr;
	std::wstring m_sDrawFlame;
	int m_iW;
	int m_iH;
	Block m_testBlock;
public:
	void init(int i_iw, int i_ih) {
		this->m_iW = i_iw;
		this->m_iH = i_ih;
		for (char i = this->m_iH; i > 0; i--) {
			std::wstring strline;
			for (char j = this->m_iW; j > 0; j--) {
				strline.append(L"□");
			}
			strline.append(L"\n");
			m_vWorldStr.push_back(strline);
		}
	}

	void update() {
		char c = getPushKey();
		switch (c)
		{
			case 'w':
				m_testBlock.m_iY--;
				if (m_testBlock.m_iY < 0) {
					m_testBlock.m_iY = 0;
				}

				break;
			case 'a':
				m_testBlock.m_iX--;
				if (m_testBlock.m_iX < 0) {
					m_testBlock.m_iX = 0;
				}
				break;
			case 's':
				m_testBlock.m_iY++;
				if (m_testBlock.m_iY > this->m_iH-1) {
					m_testBlock.m_iY = this->m_iH-2;
				}
				break;
			case 'd':
				m_testBlock.m_iX++;
				if (m_testBlock.m_iX > this->m_iW-1) {
					m_testBlock.m_iX = this->m_iW-2;
				}
				break;
			case 0x1b:
				break;

			default:
				break;
		}
		m_vWorldStr[m_testBlock.m_iY][(m_testBlock.m_iX)] = m_testBlock.m_vBlockStr[0][0];

		m_sDrawFlame.clear();
		for (char i = 0; i < this->m_iH; i++) {
			m_sDrawFlame.append( m_vWorldStr[i] );
		}
	}

	void draw() {
		wprintf(L"%s", m_sDrawFlame.c_str());
	}
};


int count = 0;
bool isFrameUpdate(char fps) {
	static system_clock::time_point prev = system_clock::now();
	static system_clock::time_point prev_sec = system_clock::now();
	
	// 現在時間
	system_clock::time_point now = system_clock::now();
	system_clock::duration dur = now - prev_sec;        // 要した時間を計算
	long long msec1 = duration_cast<milliseconds>(dur).count();
	if (1.0f < ((float)msec1 / 1000)) {
		//system("cls");
		//printf("%d fps\n", count);
		count = 0;
		prev_sec = now;
	}
	dur = now - prev;        // 要した時間を計算
	long long msec = duration_cast<milliseconds>(dur).count();
	if ((1.0f / fps) < ((float)msec / 1000)) {
		count++;
		prev = now;
		return 1;
	}
	return 0;
}


int mainLoop() {


	World world;
	world.init(100,30);

	uint64_t ui64 = 0;
	if (true) {
		do {

			if (isFrameUpdate(15)) {
				printf("\033[0;0f");
				world.update();
				world.draw();
			}
			std::this_thread::sleep_for(microseconds(10));
		} while (1);
	}
	return 0;
}