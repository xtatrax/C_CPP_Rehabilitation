/////////////////////////////////////////////////////////////////////////////////
// File:	game_main.cpp
// charset:	UTF-8
// Project:	SoW_tetris_CLI
// Author:	xtatrax
// Date:	2025/04/26
// Copyright (c) 2025 xtatrax
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////


#include "scene_base.h"

namespace tlibccp {
	namespace tetris {
		class GameMain{
			private:
				SceneBase* m_currentScene;
				SceneBase* m_nextScene;
				bool m_isRunning;
				bool m_isPaused;

				void initialize();
				void cleanup();
			public:
				GameMain();
				~GameMain();
				void update();
				void draw();
				void mainLoop();
		}; // class GameMain
	} // namespace tetris
} // namespace tlibccp