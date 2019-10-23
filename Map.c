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

    SelectedBraketDC = CreateCompatibleDC(ConsoleDC);
    SelectedBraketMap = (HBITMAP) LoadImage(NULL,
                                 TEXT("./resources/Select.bmp"),
                                 IMAGE_BITMAP,
                                 0,
                                 0,
                                 LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(SelectedBraketDC, SelectedBraketMap);
}

int MapSelect() {

    int selected = 0;
    int ReturnVal;

    PrintBackground(2);
    while(1) {
        RenturnVal = MapUpdate(&selected);
        if(ReturnVal == 1)
            return 1;
        else if(ReturnVal == -1)
            return -selected;
        MapRender(selected);
    }
}

int MapUpdate(int* selected) {
    if(kp(VK_RIGHT) && (*selected)+1 < 5) { //left
        (*selected)++;
        MapRender((*selected));
    } else if(kp(VK_LEFT) && (*selected)-1 >= 0) {  // right 
        (*selected)--;
        MapRender((*selected));
    } else if(kp(VK_RETURN)) {
        return -1;
    } else if(kp('I')) {
        return 1;
    }
    return 0;
}

void MapRender(int selected) {
    PI(5, 78, 490, 320, MapDC);
    PTI(map.countries[selected].MapX, map.countries[selected].MapX, 69, 56, SelectedBraketDC);
}

void startBattle(int selected) {
    
}