#include "Main.h"

int main() {
    printf("[*] Main Function\n");
    MainGame();
}

void MainGame() {
    printf("[*] MainGame Function\n");
    MainInit();
    while(1) {
        MainUpdate();
        MainKeyin();
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

    if(BitBlt(ConsoleDC, 0, 0, 500, 400, StartScreenDC, 0, 0, SRCCOPY)) printf("[*] Renderd\n");
    else printf("[*] Render Failed");
    while(!getch());

    printf("[*] MainInit Function\n");
    Load();
    MapSelect();
}

void MainUpdate() {

}

void MainKeyin() {

}

void MainRender() {

}