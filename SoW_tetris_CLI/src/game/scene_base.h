/////////////////////////////////////////////////////////////////////////////////
// File:	scene_base.h
// charset:	UTF-8
// Project:	SoW_tetris_CLI
// Author:	xtatrax
// Date:	2025/04/26
// Copyright (c) 2025 xtatrax
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////




namespace tlibccp {
	namespace tetris {
		class SceneBase {
			public:
				SceneBase();
				virtual ~SceneBase();
				virtual void update() = 0;
				virtual void draw() = 0;
		}; // class SceneBase
	} // namespace tetris
} // namespace tlibccp