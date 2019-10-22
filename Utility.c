#include "Utility.h"

void gotoxy(int x, int y) {
    Sleep(10);
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int key_pressed(int key) {
    return (GetAsyncKeyState(key) & 0x8000 != 0);
}

void PrintImage(HDC destDC, int sx, int sy, int dw, int dh, HDC originDC, int w, int h) {
    if(TransparentBlt(destDC, sx, sy, dw, dh, originDC, 0, 0, w, h, RGB(255, 255, 255)))
        printf("success");
}

void UtilityInit() {
    bf.BlendOp = AC_SRC_OVER;
    bf.BlendFlags = 0;
    bf.SourceConstantAlpha = 0xff;
    bf.AlphaFormat = AC_SRC_ALPHA;
}