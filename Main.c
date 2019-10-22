#include "Main.h"

int main() {
    HideCursor();
    printf("[*] Main Function\n");
    system("mode 90, 40");
    MainGame();
}

void MainGame() {
    printf("[*] MainGame Function\n");
    MainInit();
    UtilityInit();
    while(1) {
        MainUpdate();
        MainRender();
    }
}

void MainInit() {
    
    ConsoleInstance = GetModuleHandle(NULL);
    ConsoleWindow = GetConsoleWindow();
    ConsoleDC = GetDC(ConsoleWindow);

    StartScreenDC = CreateCompatibleDC(ConsoleDC);
    StartScreenMap = (HBITMAP) LoadImage(NULL,
                                         TEXT("./resources/StartScreen.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(StartScreenDC, StartScreenMap);

    if(StartScreenDC && StartScreenMap) printf("[*] Image Load Success\n");

    gotoxy(39, 30);
    printf("[*] MainInit Function\n");
    Load();
    gotoxy(39, 30);
    printf("[*] Reading End\n");

    Sleep(1000);
    system("cls");
}

void MainUpdate() {
    if(GetAsyncKeyState('I') & 0x8000) {
        if( UpgradeSelect() ) MapSelect();
    } else if(GetAsyncKeyState('O') & 0x8000) {
        // int key = MapSelect();
        // if( MapSelect() == -1) UpgradeSelect();
        // else BattleMain(key);
    }
}

void MainRender() {
    // Render Background
    // system("cls");
    // (BitBlt(ConsoleDC, 0, 0, 500, 400, StartScreenDC, 0, 0, SRCCOPY));
    BitBlt(ConsoleDC, 0, 0, 500, 400, StartScreenDC, 0, 0, SRCCOPY);
}