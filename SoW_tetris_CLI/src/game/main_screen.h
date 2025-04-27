/////////////////////////////////////////////////////////////////////////////////
// File:	main_screen
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
		class MainScene : public SceneBase {
			public:
				MainScene();
				~MainScene();
				void update() override;
				void draw() override;
		}; // class Scene
	} // namespace tetris
} // namespace tlibccp