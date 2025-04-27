#include <string>
#include <vector>

namespace sys{
	struct size{
		int width;
		int height;
	};
	int getHitKey();
	size getWindowSize();
}

namespace tlibccp{
	class DrawObject{
		protected:
			int m_width;
			int m_height;
			int m_x;
			int m_y;
			std::vector<std::vector<std::string>> m_ScreenBuffer;
	};
	class SceneBase{
			std::vector<DrawObject> m_drawObjects;
			std::vector<std::vector<std::string>> m_ScreenBuffer;
			std::string m_FrameBuffer;
		public:
			SceneBase();
			virtual ~SceneBase();
			virtual void update() = 0;
			virtual void draw() = 0;
	};
	class GameMain{
			SceneBase* m_currentScene;
			SceneBase* m_nextScene;
			bool m_isRunning;
			bool m_isPaused;

			void initialize();
			void cleanup();
		public:
			void init();
			void mainLoop();
	};
}

void main(){

}