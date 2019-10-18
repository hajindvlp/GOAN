#include "Main.h"

int main() {
    printf("[*] Main Function\n");
    system("mode 80, 25");
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
                                         TEXT("./resources/StartScreen.bmp"),
                                         IMAGE_BITMAP,
                                         0,
                                         0,
                                         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(StartScreenDC, StartScreenMap);

    if(StartScreenDC && StartScreenMap) printf("[*] Image Load Success\n");

    (BitBlt(ConsoleDC, 0, 0, 500, 400, StartScreenDC, 0, 0, SRCCOPY)) ? printf("[*] Rendered\n") : printf("[*] Render Failed");
    while(!getch()) {
        gotoxy(9, 10);
        printf("Press Key To Start");
        Sleep(500);
        printf("                  ");
        Sleep(300);
    }

    printf("[*] MainInit Function\n");
    Load();
}

void MainUpdate() {
    while(1) {
        if(GetAsyncKeyState('I') & 0x8000) {
            UpgradeSelect();
        } else if(GetAsyncKeyState('O') & 0x8000) {
            MapSelect();
        }
    }
}

void MainRender() {

}