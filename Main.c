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
                                         TEXT("./resources/background.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(StartScreenDC, StartScreenMap);

    if(StartScreenDC && StartScreenMap) printf("[*] Image Load Success\n");

    while(!kbhit()) {
        gotoxy(39, 30);
        printf("Press Key To Start");
        Sleep(500);
        gotoxy(39, 30);
        printf("                  ");
        Sleep(300);
    }

    gotoxy(39, 30);
    printf("[*] MainInit Function\n");
    Load();
    gotoxy(39, 30);
    printf("[*] Reading End\n");

    UtilityInit();

    Sleep(1000);
    system("cls");
}

void MainUpdate() {
    if(GetAsyncKeyState('I') & 0x8000) {
        UpgradeSelect();
    } else if(GetAsyncKeyState('O') & 0x8000) {
        MapSelect();
    }
}

void MainRender() {
    // Render Background
    // system("cls");
    // (BitBlt(ConsoleDC, 0, 0, 500, 400, StartScreenDC, 0, 0, SRCCOPY));
    BitBlt(ConsoleDC, 0, 0, 500, 400, gang.characters[0].CharacterWalkSpriteDC[0], 0, 0, SRCCOPY);
}