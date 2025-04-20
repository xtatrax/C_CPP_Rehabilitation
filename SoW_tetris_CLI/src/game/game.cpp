

#include "game.h"

namespace tlibccp {
	namespace tetris {
		Game::Game() : m_currentScene(nullptr), m_nextScene(nullptr), m_isRunning(false), m_isPaused(false) {
			initialize();
		}

		Game::~Game() {
			cleanup();
		}

		void Game::initialize() {
			m_isRunning = true;
			m_isPaused = false;
		}

		void Game::cleanup() {
			if (m_currentScene) {
				delete m_currentScene;
				m_currentScene = nullptr;
			}
			if (m_nextScene) {
				delete m_nextScene;
				m_nextScene = nullptr;
			}
		}

		void Game::start() {
			if (m_currentScene) {
				m_currentScene->start();
			}
		}
		void Game::stop() {
			if (m_currentScene) {
				m_currentScene->stop();
			}
			m_isRunning = false;
		}
		void Game::pause() {
			if (m_currentScene) {
				m_currentScene->pause();
			}
			m_isPaused = true;
		}
		void Game::resume() {
			if (m_currentScene) {
				m_currentScene->resume();
			}
			m_isPaused = false;
		}
		void Game::update() {
			if (m_currentScene) {
				m_currentScene->update();
			}
		}
		void Game::draw() {
			if (m_currentScene) {
				m_currentScene->draw();
			}
		}
	} // namespace tetris
} // namespace tlibccp
