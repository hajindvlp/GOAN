#include "Map.h"

void MapInit() {
    MapDC = CreateCompatibleDC(ConsoleDC);
    MapMap = (HBITMAP) LoadImage(NULL,
                                 TEXT("./resources/Map.bmp"),
                                 IMAGE_BITMAP,
                                 0,
                                 0,
                                 LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(MapDC, MapMap);
}

int MapSelect() {

    int selected = 0;


    PrintBackground(2);
    while(1) {
        if(key_pressed(VK_LEFT)) { //left
            selected++;
            MapRender(selected);
        } else if(key_pressed(VK_LEFT)) {  // right 
            selected--;
            MapRender(selected);
        } else if(key_pressed(VK_RETURN)) {
            startBattle(selected);
            break;
        } else if(key_pressed('I')) {
            return -1;
        } 
        // else if(getch() == 12) {
        //     BattleMain(selected);
        //     break;
        // }
    }
}

void MapRender(int selected) {

    PrintImage(5, 80, 490, 320, MapDC);

}

void startBattle(int selected) {

}