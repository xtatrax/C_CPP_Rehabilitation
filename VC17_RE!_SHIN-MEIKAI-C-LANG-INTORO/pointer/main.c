
#include <stdio.h>

void main(){
	char *str = "Hello, World!";
	printf("A %s (%p)\n", str, str);
	(*str)++;
	printf("B %s (%p)\n", str, str);
	(*(str + 1)) = 'A';
	printf("C %s (%p)\n", str, str);

	const char *cstr = "const Hello, World!";
	printf("D %s (%p)\n", cstr, cstr);
	//(*cstr)++;
	printf("E %s (%p)\n", cstr, cstr);
	//(*(cstr + 1)) = 'A';
	printf("F %s (%p)\n", cstr, cstr);

}

/*
void main(){
	int a = 10;
	int *p = &a;

	printf("Value of a: %d\n", a);
	printf("Address of a: %p\n", (void*)&a);
	printf("Value of p: %p\n", (void*)p);
	printf("Value pointed to by p: %d\n", *p);

	*p = 20; // Change the value of a using the pointer
	printf("New value of a: %d\n", a);
}

*/