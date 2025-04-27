

#include <conio.h>
#include <cctype>

namespace tlibccp {
	namespace sys{
		int getHitKey(){
			if (_kbhit()) {
				return tolower(_getch());
			}
			return 0;
		}
	} // namespace sys
} // namespace tlibccp