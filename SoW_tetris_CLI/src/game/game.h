

#include "scene_base.h"

namespace tlibccp {
	namespace tetris {
		class Game{
			private:
				SceneBase* m_currentScene;
				SceneBase* m_nextScene;
				bool m_isRunning;
				bool m_isPaused;

				void initialize();
				void cleanup();
			public:
				Game();
				~Game();
				void start();
				void stop();
				void pause();
				void resume();
				void update();
				void draw();
		}; // class Game
	} // namespace tetris
} // namespace tlibccp