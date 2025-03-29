#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string>
#include "main_loop.h"
int main() {
    setlocale(LC_ALL, "ja_JP.Utf-8");
    //printf("\e[8;100;100t\n");


    if (false) {
        std::wstring test = L"１２３４５６７８９";

        std::wstring test2 = L"●□■◆";

        wprintf(L"%s \n", test.c_str());
        wprintf(L"%s \n", test2.c_str());
        test.replace(3, test2.length(), test2);
        wprintf(L"%s \n", test.c_str());

        system("help");
    } else {
        constexpr CONSOLE_CURSOR_INFO cursor{ 1, FALSE };

        CONSOLE_CURSOR_INFO init;

        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &init); // カーソルの初期状態を得る。

        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor); // カーソルを不可視化する。

        //system("chcp 65001");
        //wprintf(L"漢字を表示\n");
        //wprintf(L"□ あああ");
        mainLoop();

        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &init); // カーソルの状態を元に戻す。
    }
    getchar();
}