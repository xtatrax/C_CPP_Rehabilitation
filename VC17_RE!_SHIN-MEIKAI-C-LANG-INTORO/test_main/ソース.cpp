
#include <stdio.h>

extern c{

void main() {
	char* str = "(Hello, World!)";
	printf("A %s (%p)\n", str, str);
	(*str)++;
	printf("B %s (%p)\n", str, str);
	(*(str + 1)) = 'A';
	printf("C %s (%p)\n", str, str);

	const char* cstr = "const Hello, World!";
	printf("D %s (%p)\n", cstr, cstr);
	//(*cstr)++;
	printf("E %s (%p)\n", cstr, cstr);
	//(*(cstr + 1)) = 'A';
	printf("F %s (%p)\n", cstr, cstr);

}
}