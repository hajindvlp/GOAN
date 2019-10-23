#include "Utility.h"

void gotoxy(int x, int y) {
    // Sleep(10);
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int kp(int key) {
    return (GetAsyncKeyState(key) & 0x8000 != 0);
}

int kpw(int key) {
    while(!kbhit())
        return (getch() == key);
}

void UtilityInit() {
    MenuUpgradeDC = CreateCompatibleDC(ConsoleDC);
    MenuMapDC = CreateCompatibleDC(ConsoleDC);
    BlankDC = CreateCompatibleDC(ConsoleDC);

    MenuUpgradeMap = (HBITMAP) LoadImage(NULL,
                                         TEXT("./resources/Menu_Upgrade.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    MenuMapMap = (HBITMAP) LoadImage(NULL,
                                         TEXT("./resources/Menu_Map.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    BlankMap = (HBITMAP) LoadImage(NULL,
                                         TEXT("./resources/Blank.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    SelectObject(MenuUpgradeDC, MenuUpgradeMap);
    SelectObject(MenuMapDC, MenuMapMap);
    SelectObject(BlankDC, BlankMap);
}

void PTI(int sx, int sy, int w, int h, HDC originDC) {
    TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));
}

void PTIB(int sx, int sy, int w, int h, HDC originDC) {
    BitBlt(ConsoleDC, sx, sy, w, h, BlankDC, w, h, SRCCOPY);
    TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));
}

void PI(int sx, int sy, int w, int h, HDC originDC) {
    BitBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, SRCCOPY);
}

void PrintBackground(int UMCode) {
    if(UMCode == 1) {
        BitBlt(ConsoleDC, 0, 0, 500, 400, MenuUpgradeDC, 0, 0, SRCCOPY);
    } else if(UMCode == 2) {
        BitBlt(ConsoleDC, 0, 0, 500, 400, MenuMapDC, 0, 0, SRCCOPY);
    }
}