// TextCell
#pragma once
union TextCellStatus{
	char status;
	bool isLock : 1;
	char type :4;
	char color: 3;
};
enum TCType{
	// max 16
	empty = 0b0000,
	block,
	wall,
	tine,
	score,
};
enum TCColor{
	// max 7
	Default = 0b000,
	R = 0b001,
	G = 0b010,
	B = 0b011,
	C = 0b100,
	M = 0b101,
	Y = 0b110,
	gray = 0b111
};
struct BlockColor{
	// 文字列の定数化これでいいんだっけ？。。。
	const char *R = "\e[91;41m";
	const char *G = "\e[92;42m";
	const char *B = "\e[94;44m";
	const char *C = "\e[96;46m";
	const char *M = "\e[95;45m";
	const char *Y = "\e[93;43m";
	inline const char* convTCC(TCColor tcc) const {
		switch(tcc){
			case TCColor::R:
				return R;
			break;
			case TCColor::G:
				return G;
			break;
			case TCColor::B:
				return B;
			break;
			case TCColor::Y:
				return Y;
			break;
			case TCColor::M:
				return M;
			break;
			case TCColor::C:
				return C;
			break;
			
		}
	}
};