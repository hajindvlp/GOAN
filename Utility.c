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

void HideCursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void LI(HDC* DC, HBITMAP* Map, char* path) {
    (*DC) = CreateCompatibleDC(ConsoleDC);
    (*Map) = (HBITMAP) LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(*DC, *Map);
}

void UtilityInit() {
    LI(&MenuUpgradeDC, &MenuUpgradeMap, "./resources/Menu_Upgrade.bmp");
    LI(&MenuMapDC, &MenuMapMap, "./resources/Menu_Map.bmp");
    LI(&BlankDC, &BlankMap, "./resources/Blank.bmp");
    LI(&BattleBackgroundDC, &BattleBackgroundMap, "./resources/BattleBackground.bmp");
    LI(&BattleCharacterSelectBoxDC, &BattleCharacterSelectBoxMap, "./resources/BattleCharacterBox.bmp");
    
    mciSendString("open resources/Sounds/music.mp3 type mpegvideo", NULL,0,0);
}

int GMX() {
	POINT pt;
    GetCursorPos(&pt);
	ScreenToClient(ConsoleWindow, &pt);
    return pt.x;
}

int GMY() {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(ConsoleWindow, &pt);
    return pt.y;
}

void PT(int sx, int sy, int w, int h, HDC originDC) {
    TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));
}

void PTB(int sx, int sy, int w, int h, HDC originDC) {
    BitBlt(ConsoleDC, sx, sy, w, h, BlankDC, w, h, SRCCOPY);
    TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));
}

void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC) {
    BitBlt(ConsoleDC, sx, sy, w, h, originDC, ox, oy, SRCCOPY);
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