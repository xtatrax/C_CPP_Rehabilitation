/////////////////////////////////////////////////////////////////////////////////
// File:	game_main.h
// charset:	UTF-8
// Project:	SoW_tetris_CLI
// Author:	xtatrax
// Date:	2025/04/26
// Copyright (c) 2025 xtatrax
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////


#include "game_main.h"

namespace tlibccp {
	namespace tetris {
		GameMain::GameMain() : m_currentScene(nullptr), m_nextScene(nullptr), m_isRunning(false), m_isPaused(false) {
			initialize();
		}

		GameMain::~GameMain() {
			cleanup();
		}

		void GameMain::initialize() {
			m_isRunning = true;
			m_isPaused = false;
		}

		void GameMain::cleanup() {
			if (m_currentScene) {
				delete m_currentScene;
				m_currentScene = nullptr;
			}
			if (m_nextScene) {
				delete m_nextScene;
				m_nextScene = nullptr;
			}
		}

		void GameMain::update() {
			if (m_currentScene) {
				m_currentScene->update();
			}
		}
		void GameMain::draw() {
			if (m_currentScene) {
				m_currentScene->draw();
			}
		}
		void GameMain::mainLoop() {
			while (m_isRunning) {
				update();
				draw();
			}
		}
	} // namespace tetris
} // namespace tlibccp
