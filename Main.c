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
    MapInit();
    
    MainRender();
    MainUpdate();
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
    int key = 0; 
    
    while(1) {
        if(key == 1) {
            key = UpgradeSelect();
        } else if(key == 2) {
            key = MapSelect();
        } else if(key == 0) {
            if(GetAsyncKeyState('I') & 0x8000) {
                key =  1;
            } else if(GetAsyncKeyState('O') & 0x8000) {
                key = 2;
            }
        }
        gotoxy(40, 29);
        printf("[*] key : %d", key);
    }
}

void MainRender() {
    PI(0, 0, 500, 400, StartScreenDC);
}