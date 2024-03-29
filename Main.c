#include "Main.h"

int main() {
    HideCursor();
    system("mode 100, 28");
    MainGame();
}

void MainGame() {    
    MainInit();
    MainRender(0);
    MainUpdate();
}

void MainInit() {
    SetConsoleTitle("Main");
    Load();
    UtilityInit();
    MapInit();

    PM("Main.mp3");
    // char Command[201];
    //sprintf(Command, "open resources/Sounds/%s type mpegvideo", path);
    // mciSendString("open resources/Sounds/Main.mp3 type mpegvideo", NULL, 0, 0);
    //sprintf(Command, "play resources/Sounds/%s", path);
    // mciSendString("play resources/Sounds/Main.mp3", NULL, 0, 0);
}

void MainUpdate() {
    int key = 0; 
    int selected = 0;
    
    while(1) {
        if(key == 1) {
            key = UpgradeSelect();
        } else if(key == 2) {
            key = MapSelect();
        } else if(key == -1) {
            PlayerFile = fopen("./resources/Files/PLAYER", "w+");
            for(int i=0 ; i<5 ; i++) fprintf(PlayerFile, "0 ");
            key = 1;
        } else if(key == 3) {
            return;
        } else if(key == 0) {
            if(GetAsyncKeyState('I') & 0x8000) {
                key =  1;
            } else if(GetAsyncKeyState('O') & 0x8000) {
                key = -1;
            }
        }

        if(key == 0) {
            if(kp(VK_UP) && selected > 0) selected --, MainRender(selected); 
            else if(kp(VK_DOWN) && selected < 2) selected ++, MainRender(selected); 
            if(kp(VK_RETURN)) key = selected+1;
            if(GMX() >= 42 && GMX() <= 42+250) {
                if(GMY() >= 175 && GMY() <= 215 && selected != 0) selected = 0, MainRender(selected);
                if(GMY() >= 230 && GMY() <= 265 && selected != 1) selected = 1, MainRender(selected);
                if(GMY() >= 270 && GMY() <= 330 && selected != 2) selected = 2, MainRender(selected);

                if(kp(VK_LBUTTON) && selected != 1) key = selected+1;
                else if(kp(VK_LBUTTON) && selected == 1) key = -1;
            }
        }
        Sleep(1000/30);
    }
}

void MainRender(int selected) {
    // render background
    PI(0, 0, 800, 450, StartScreenDC);

    // render selection bar
    if(selected == 0) {
        PT(42, 250, 250, 30, MenuSelectDC);
    } else if(selected == 1) {
        PT(42, 310, 250, 30, MenuSelectDC);
    } else if(selected == 2) {
        PT(42, 380, 250, 30, MenuSelectDC);
    }
}