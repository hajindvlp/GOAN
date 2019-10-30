#include "Utility.h"

void UtilityInit() {

    srand(time(0)); 

    LI(&MenuUpgradeDC, &MenuUpgradeMap, "./resources/Upgrade.bmp");
    LI(&MenuMapDC, &MenuMapMap, "./resources/Map.bmp");
    LI(&BlankDC, &BlankMap, "./resources/Blank.bmp");

    LI(&BattleBackgroundDC, &BattleBackgroundMap, "./resources/BattleBackground.bmp");

    LI(&MenuSelectDC, &MenuSelectMap, "./resources/SelectMenu.bmp");
    LI(&ArrowLeftDC, &ArrowLeftMap, "./resources/ArrowLeft.bmp");
    LI(&ArrowRightDC, &ArrowRightMap, "./resources/ArrowRight.bmp");
    
    for(int i=0 ; i<26 ; i++) {
        char path[101];
        sprintf(path, "./resources/Alphabet/%d.bmp", i);
        LI(&AlphabetDC[i], &AlphabetMap[i], path);
    }

    for(int i=0 ; i<10 ; i++) {
        char path[101];
        sprintf(path, "./resources/Number/%d.bmp", i);
        LI(&NumberDC[i], &NumberMap[i], path);
    }

    mciSendString("open resources/Sounds/music.mp3 type mpegvideo", NULL,0,0);
}

int RR(int ratio) {
    int r = rand();
    return ((r%100+100)%100 <= ratio);
}

void gotoxy(int x, int y) {
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int kp(int key) {
    return (GetAsyncKeyState(key) & 0x8000);
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

// void LO(Object object) {
//     object.(*DC) = CreateCompatibleDC(ConsoleDC);
//     object.(*Map) = (HBITMAP) LoadImage(NULL, object.path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//     SelectObject(object.(*DC), object.(*DC));
// }


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

int MIA(int sx, int sy, int w, int h) {
    int x = GMX(), y = GMY();
    return ( x>=sx && y>=sy && x<=sx+w && y<=sy+h );
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

// void PS(int w, int h, char* Str) {
//     for(int i=0 ; Str[i] ; i++) {
//         PT()
//     }
// }