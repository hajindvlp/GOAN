#include "Upgrade.h"

int UpgradeSelect() {
    
    int selected = -1;

    UpgradeInit();
    while(1) {
        Debug();
        if( UpgradeUpdate(&selected) )
            return 2;
        UpgradeRender(selected);
        Sleep(100);
    }    
}

void UpgradeInit() {

    SetConsoleTitle("Upgrade Screen");
    ToMapCnt = 0;
    // UC[0] = { 107, 175, 100, 100 };
    // UC[1] = { 107, 175, 100, 100 };
    // UC[2] = { 100, 135, 150, 150 };
    // UC[3] = { 100, 135, 150, 150 };
    // UC[4] = { 100, 135, 150, 150 };
    // UC[5] = { 100, 135, 150, 150 };
}

int UpgradeUpdate(int *selected) {
    if(kp('O')) {
        return 1;
    }
    if( MIA(460, 308, 92, 20) && kp(VK_LBUTTON)) {
        return 1;
    }
    if(kp(VK_RIGHT)) {
        (*selected) ++;
    }
    if(kp(VK_LEFT)) {
        (*selected) --;
    }
    if(MIA(434, 65, 80, 80) && kp(VK_LBUTTON)) (*selected) = 0;
    if(MIA(505, 65, 80, 80) && kp(VK_LBUTTON)) (*selected) = 1;
    return 0;
}

void UpgradeRender(int selected) {

    // render store background
    PI(0, 0, 800, 450, MenuUpgradeDC);

    // render character icons
    // first one
    PT( 540, 100, 80, 80, gang.characters[0].UpgradeIconDC );
    PT( 630, 100, 80, 80, gang.characters[1].UpgradeIconDC );
    PT( 540, 190, 80, 80, gang.characters[2].UpgradeIconDC );
    PT( 630, 190, 80, 80, gang.characters[3].UpgradeIconDC );
    PT( 540, 280, 80, 80, gang.characters[4].UpgradeIconDC );
    PT( 630, 280, 80, 80, gang.characters[5].UpgradeIconDC );
    // 566 378 

    ToMapCnt %= 3;
    PT(566, 378, 153, 52, ToMapDC[ToMapCnt++]);

    // render character Sprite
    if(selected >= 0)
        PT( 100, 146, 150, 150, 
               gang.characters[selected].AttackSpriteDC[(gang.characters[selected].AttackSpriteCnt++)%gang.characters[selected].AttackSpriteNum]);
}