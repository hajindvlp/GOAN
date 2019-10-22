#include "Utility.h"

void gotoxy(int x, int y) {
    Sleep(10);
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int key_pressed(int key) {
    return (GetAsyncKeyState(key) & 0x8000 != 0);
}

void UtilityInit() {
    UpgradeDC = CreateCompatibleDC(ConsoleDC);
    MapDC = CreateCompatibleDC(ConsoleDC);
    BlankDC = CreateCompatibleDC(ConsoleDC);

    UpgradeMap = (HBITMAP) LoadImage(NULL,
                                         TEXT("./resources/Menu_Upgrade.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    MapMap = (HBITMAP) LoadImage(NULL,
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

    SelectObject(UpgradeDC, UpgradeMap);
    SelectObject(BlankDC, BlankMap);
    SelectObject(MapDC, MapMap);
}

void PrintImage(int sx, int sy, int w, int h, HDC originDC) {
    TransparentBlt(ConsoleDC, sx, sy, w, h, BlankDC, 0, 0, w, h, RGB(255, 0, 255));
    TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));
}

void PrintBackground(int UMCode) {
    if(UMCode) {
        BitBlt(ConsoleDC, 0, 0, 500, 400, UpgradeDC, 0, 0, SRCCOPY);
    } else {
        BitBlt(ConsoleDC, 0, 0, 500, 400, MapDC, 0, 0, SRCCOPY);
    }
}