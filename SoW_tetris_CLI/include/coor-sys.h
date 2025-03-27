
#pragma ones

namespace tlib {
	typedef struct Pos2D {
		int x;
		int y;
		Pos2D(int x, int y) { this->x = x; this->y = y; }
		Pos2D(Pos2D const &other)  { this->x = other.x; this->y = other.y; }
		Pos2D() { this->x = 0; this->y = 0; }
	};

	class World{
		int x;
	};

}