#define WIN32_LEAN_AND_MEAN

#include <SetPointer.h>
#include <windows.h>
#include <iostream>

// set the in/out pointer to position (x, y). If mode == 0 -> std::cin, else -> std::cout
void gotoxy(int x, int y, bool mode) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    if (mode) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    else SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), coord);
}

// clear one line of console
void clear(int x, int y) {
    gotoxy(x, y, 1);
    std::cout << "                                                                  ";
    gotoxy(x, y, 1);
}