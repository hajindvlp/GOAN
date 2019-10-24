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
    mciSendString("play resources/Sounds/music.mp3", NULL, 0, 0);
    
    HANDLE hInput;
    DWORD prev_mode;
    GetConsoleMode(hInput, &prev_mode); 
    SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
    
    MainRender(0);
    MainUpdate();
}

void MainInit() {
    
    ConsoleInstance = GetModuleHandle(NULL);
    ConsoleWindow = GetConsoleWindow();
    ConsoleDC = GetDC(ConsoleWindow);

    LI(&StartScreenDC, &StartScreenMap, "./resources/StartScreen.bmp");

    Load();

    Sleep(1000);
    system("cls");
}

void MainUpdate() {
    int key = 0; 
    int selected = 0;
    
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

        if(key == 0) {
            if(kp(VK_UP) && selected > 0) selected --, MainRender(selected); 
            if(kp(VK_DOWN) && selected < 2) selected ++, MainRender(selected); 
            else if(GMX() >= 42 && GMX() <= 42+250) {
                if(GMY() >= 175 && GMY() <= 215 ) selected = 0, MainRender(selected);
                if(GMY() >= 230 && GMY() <= 265 ) selected = 1, MainRender(selected);
                if(GMY() >= 270 && GMY() <= 330 ) selected = 2, MainRender(selected);
            }
        }
    }
}

void MainRender(int selected) {
    PI(0, 0, 800, 450, StartScreenDC);
    if(selected == 0) {
        PT(42, 250, 250, 30, MenuSelectDC);
    } else if(selected == 1) {
        PT(42, 310, 250, 30, MenuSelectDC);
    } else if(selected == 2) {
        PT(42, 380, 250, 30, MenuSelectDC);
    }
}