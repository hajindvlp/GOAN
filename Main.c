#include "Main.h"

int main() {
    HideCursor();
    system("mode 80, 30");
    MainGame();
}

void MainGame() {    
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

    Load();

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
    }
}

void MainRender() {
    PI(0, 0, 500, 400, StartScreenDC);
}