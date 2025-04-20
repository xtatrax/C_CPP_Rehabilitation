



namespace tlibccp {
	namespace tetris {
		class SceneBase {
			public:
				SceneBase();
				virtual ~SceneBase();
				virtual void start() = 0;
				virtual void stop() = 0;
				virtual void pause() = 0;
				virtual void resume() = 0;
				virtual void update() = 0;
				virtual void draw() = 0;
		}; // class SceneBase
	} // namespace tetris
} // namespace tlibccp