#include "Utility.h"

void UtilityInit() {

    srand(time(0)); 
    
    ConsoleInstance = GetModuleHandle(NULL);
    ConsoleWindow = GetConsoleWindow();
    ConsoleDC = GetDC(ConsoleWindow);

    LI(&StartScreenDC, &StartScreenMap, "./resources/Main/StartScreen.bmp");
    LI(&MenuSelectDC, &MenuSelectMap,   "./resources/Main/SelectMenu.bmp");

    LI(&MenuUpgradeDC, &MenuUpgradeMap, "./resources/Upgrade/Upgrade.bmp");

    LI(&MenuMapDC, &MenuMapMap,           "./resources/Map/Map.bmp");
    LI(&BracketLeftDC, &BracketLeftMap,   "./resources/Map/BracketLeft.bmp");
    LI(&BracketRightDC, &BracketRightMap, "./resources/Map/BracketRight.bmp");

    LI(&BattleBackgroundDC, &BattleBackgroundMap, "./resources/Battle/BattleBackground.bmp");
    LI(&CoinDC, &CoinMap,                         "./resources/Battle/Coin.bmp");
    LI(&LooseScreenDC, &LooseScreenMap,           "./resources/Battle/Loose.bmp");
    LI(&WinScreenDC, &WinScreenMap,               "./resources/Battle/Win.bmp");
    LI(&BlackDC, &BlackMap,                       "./resources/Battle/Black.bmp");

    LI(&NumberRawDC, &NumberRawMap, "./resources/Number/number.bmp");

    BattleBackBldFunc.BlendOp = AC_SRC_OVER;
    BattleBackBldFunc.BlendFlags = 0;
    BattleBackBldFunc.SourceConstantAlpha = 0;
    BattleBackBldFunc.AlphaFormat = 0;


    // LI(&ArrowLeftDC, &ArrowLeftMap, "./resources/ArrowLeft.bmp");
    // LI(&ArrowRightDC, &ArrowRightMap, "./resources/ArrowRight.bmp");
    
    // for(int i=0 ; i<26 ; i++) {
    //     char path[101];
    //     sprintf(path, "./resources/Alphabet/%d.bmp", i);
    //     LI(&AlphabetDC[i], &AlphabetMap[i], path);
    // }

    for(int i=0 ; i<10 ; i++) TransparentBlt(NumbersDC[i], 0, 0, 32, 50, NumberRawDC, i*32, 0, 32, 50, RGB(255, 0, 255));

    // mciSendString("open resources/Sounds/music.mp3 type mpegvideo", NULL,0,0);
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

void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC) {
    BitBlt(ConsoleDC, sx, sy, w, h, originDC, ox, oy, SRCCOPY);
}

void PI(int sx, int sy, int w, int h, HDC originDC) {
    BitBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, SRCCOPY);
}


void PN(int sx, int sy, int w, int h, int number) {
    
}

// void PS(int w, int h, char* Str) {
//     for(int i=0 ; Str[i] ; i++) {
//         PT()
//     }
// }