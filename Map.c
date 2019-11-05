#include "Map.h"

int MapSelect() {

    int selected = 0;
    
    SetConsoleTitle("Map Screen");

    while(1) {
        if(MapUpdate(&selected))
            return 1;
        MapRender(selected);
        Sleep(100);
    }
}

void MapInit() {

    // hard code things -- hate this
    oldSelected = -1;
    ToUpgradeCnt = 0;

    int BracktTmp[6][4] = { 
        {457, 300, 602, 300},
        {553, 130, 643, 130},
        {380, 215, 460, 215},
        {270, 110, 376, 110},
        {105, 279, 274, 279}
    }, EnemyTmp[6][4]  = {
        {370, 245, 140, 25},
        {450, 115, 85 , 20},
        {310, 180, 80 , 20},
        {230, 100, 95 , 20},
        {100, 215, 145, 55}
    };

    for(int i=0 ; i<6 ; i++) 
        for(int j=0 ; j<4 ; j++) 
            BracketCoord[i][j] = BracktTmp[i][j];

    for(int i=0 ; i<6 ; i++) 
        for(int j=0 ; j<4 ; j++) 
            EnemyCoord[i][j] = EnemyTmp[i][j];
}

int MapUpdate(int* selected) {
    if(kp(VK_RIGHT) && (*selected)+1 < 5) { //left
        (*selected)++;
        MapRender((*selected));
    } else if(kp(VK_LEFT) && (*selected)-1 >= 0) {  // right 
        (*selected)--;
        MapRender((*selected));
    } else if(kp(VK_RETURN)) {
        return startBattle(*selected);
    } 

    for(int i=0 ; i<5 ; i++) 
        if(MIA(EnemyCoord[i][0], EnemyCoord[i][1], EnemyCoord[i][2], EnemyCoord[i][3])) {
            if(*selected != i) *selected = i, MapRender(i);
            if(kp(VK_LBUTTON)) {
                return startBattle(*selected);
            } 
        }

    // Goes To Upgrade Menu
    if(kp('I')) {
        return 1;
    } else if(GMX() >= 12 && GMX() <= 98 && GMY() >= 14 && GMY() <= 47 && kp(VK_LBUTTON)) {
        return 1;
    }
    return 0;
}

void MapRender(int selected) {

    PI(0, 0, 800, 450, MenuMapDC);
    PT(BracketCoord[selected][0], BracketCoord[selected][1], 9, 43, BracketLeftDC);
    PT(BracketCoord[selected][2], BracketCoord[selected][3], 9, 43, BracketRightDC);
    oldSelected = selected;

    ToUpgradeCnt %= 3;
    PT(15, 15, 153, 52, ToUpgradeDC[ToUpgradeCnt++]);
}

int startBattle(int selected) {
    return BattleMain(selected+1);
}