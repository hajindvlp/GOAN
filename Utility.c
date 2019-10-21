#include "Utility.h"

void gotoxy(int x, int y) {
    Sleep(300);
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}