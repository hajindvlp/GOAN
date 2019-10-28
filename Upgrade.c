#include "Upgrade.h"

int UpgradeSelect() {
    
    int selected = -1;

    while(1) {
        if( UpgradeUpdate(&selected) )
            return 2;
        UpgradeRender(selected);
        Sleep(300);
    }    
}

int UpgradeUpdate(int *selected) {
    if(kp('O')) {
        return 1;
    }
    if( MIA(100, 14, 96, 33) && kp(VK_LBUTTON)) {
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

    // render character Sprite
    if(selected >= 0)
        PT( 130, 195, 100, 100, 
               gang.characters[selected].AttackSpriteDC[(gang.characters[selected].AttackSpriteCnt++)%gang.characters[selected].AttackSpriteNum]);
}