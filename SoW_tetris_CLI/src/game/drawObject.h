/////////////////////////////////////////////////////////////////////////////////
// File:	drawObject.h
// charset:	UTF-8
// Project:	SoW_tetris_CLI
// Author:	xtatrax
// Date:	2025/04/26
// Copyright (c) 2025 xtatrax
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <string>

namespace tlibccp
{
	class DrawObject{
		protected:
			int m_width;
			int m_height;
			int m_x;
			int m_y;
			std::vector<std::vector<std::string>> m_ScreenBuffer;
	};
} // namespace tlibccp