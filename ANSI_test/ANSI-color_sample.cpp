#include <stdio.h>
#include <locale.h>
#include <cstdlib>

int main() {
	// ANSI escape codes for colors
	const char* red = "\033[31m";
	const char* green = "\033[32m";
	const char* blue = "\033[34m";
	const char* reset = "\033[0m";
	const char* yellow = "\033[33m";
	const char* magenta = "\033[35m";
	const char* cyan = "\033[36m";
	const char* white = "\033[37m";

	const char* bright_red = "\033[91m";
	const char* bright_green = "\033[92m";
	const char* bright_yellow = "\033[93m";
	const char* bright_blue = "\033[94m";
	const char* bright_magenta = "\033[95m";
	const char* bright_cyan = "\033[96m";
	const char* bright_white = "\033[97m";

	const char* bg_red = "\033[41m";
	const char* bg_green = "\033[42m";
	const char* bg_blue = "\033[44m";
	const char* bg_yellow = "\033[43m";
	const char* bg_magenta = "\033[45m";
	const char* bg_cyan = "\033[46m";
	const char* bg_white = "\033[47m";

	const char* bg_bright_red = "\033[101m";
	const char* bg_bright_green = "\033[102m";
	const char* bg_bright_yellow = "\033[103m";
	const char* bg_bright_blue = "\033[104m";
	const char* bg_bright_magenta = "\033[105m";
	const char* bg_bright_cyan = "\033[106m";
	const char* bg_bright_white = "\033[107m";
	setlocale(LC_CTYPE, "ja_JP.UTF-8");
	system("CHCP 65001");
	// Print colored text
	printf("%s ■ This text is red.%s\n", red, reset);
	printf("%s ■ This text is green.%s\n", green, reset);
	printf("%s ■ This text is blue.%s\n", blue, reset);
	printf("%s ■ This text is yellow.%s\n", yellow, reset);
	printf("%s ■ This text is magenta.%s\n", magenta, reset);
	printf("%s ■ This text is cyan.%s\n", cyan, reset);
	printf("%s ■ This text is white.%s\n", white, reset);

	printf("%s ■ This text is bright red.%s\n", bright_red, reset);
	printf("%s ■ This text is bright green.%s\n", bright_green, reset);
	printf("%s ■ This text is bright blue.%s\n", bright_blue, reset);
	printf("%s ■ This text is bright yellow.%s\n", bright_yellow, reset);
	printf("%s ■ This text is bright magenta.%s\n", bright_magenta, reset);
	printf("%s ■ This text is bright cyan.%s\n", bright_cyan, reset);
	printf("%s ■ This text is bright white.%s\n", bright_white, reset);

	printf("%s ■ This text has a red background.%s\n", bg_red, reset);
	printf("%s ■ This text has a green background.%s\n", bg_green, reset);
	printf("%s ■ This text has a blue background.%s\n", bg_blue, reset);
	printf("%s ■ This text has a yellow background.%s\n", bg_yellow, reset);
	printf("%s ■ This text has a magenta background.%s\n", bg_magenta, reset);
	printf("%s ■ This text has a cyan background.%s\n", bg_cyan, reset);
	printf("%s ■ This text has a white background.%s\n", bg_white, reset);

	printf("%s ■ This text has a bright red background.%s\n", bg_bright_red, reset);
	printf("%s ■ This text has a bright green background.%s\n", bg_bright_green, reset);
	printf("%s ■ This text has a bright blue background.%s\n", bg_bright_blue, reset);
	printf("%s ■ This text has a bright yellow background.%s\n", bg_bright_yellow, reset);
	printf("%s ■ This text has a bright magenta background.%s\n", bg_bright_magenta, reset);
	printf("%s ■ This text has a bright cyan background.%s\n", bg_bright_cyan, reset);
	printf("%s ■ This text has a bright white background.%s\n", bg_bright_white, reset);


	return 0;
}