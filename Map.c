#include "Map.h"

void MapInit() {
    LI(&BracketLeftDC, &BracketLeftMap, "./resources/BracketLeft.bmp");
    LI(&BracketRightDC, &BracketRightMap, "./resources/BracketRight.bmp");

    // hard code things -- hate this
    oldSelected = -1;
}

int MapSelect() {

    int selected = 0;

    while(1) {
        if(MapUpdate(&selected))
            return 1;
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
        startBattle(*selected);
    } 

    // printf("%d %d\n", GMX(), GMY());
    if     (MIA(370, 245, 140, 25) && *selected != 0) *selected = 0, MapRender(0);
    else if(MIA(450, 115, 85, 20)  && *selected != 1) *selected = 1, MapRender(1);
    else if(MIA(310, 180, 80, 20)  && *selected != 2) *selected = 2, MapRender(2);
    else if(MIA(230, 100, 95, 20)  && *selected != 3) *selected = 3, MapRender(3);
    else if(MIA(100, 215, 145, 55) && *selected != 4) *selected = 4, MapRender(4);

    // Goes To Upgrade Menu
    if(kp('I')) {
        return 1;
    } else if(GMX() >= 12 && GMX() <= 98 && GMY() >= 14 && GMY() <= 47 && kp(VK_LBUTTON)) {
        return 1;
    }
    return 0;
}

void MapRender(int selected) {

    if(oldSelected != selected) {
        PI(0, 0, 800, 450, MenuMapDC);
        PT(BracketCoord[selected][0], BracketCoord[selected][1], 9, 43, BracketLeftDC);
        PT(BracketCoord[selected][2], BracketCoord[selected][3], 9, 43, BracketRightDC);
        oldSelected = selected;
    }

    /*
    int oldX, oldY, X, Y;

    X = GMX();
    Y = GMY();
    if(X!=oldX && Y!=oldY) {
        PI(0, 0, 800, 450, MapDC);
        PT(X+23, Y+28, 69, 56, SelectedBraketDC);
        oldX = X, oldY = Y;
    }
    */
}

void startBattle(int selected) {
    BattleMain(selected);
}