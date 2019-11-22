#include "Upgrade.h"

int UpgradeSelect() {
    
    int selected = -1;

    system("mode 100, 28");
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
}

int UpgradeUpdate(int *selected) {
    if(kp('O') || (MIA(460, 308, 92, 20) && kp(VK_LBUTTON)) ) {
        return 1;
    }
    if(kp(VK_RIGHT) && *selected < 5) {
        (*selected) ++;
    }
    if(kp(VK_LEFT) && *selected > 0) {
        (*selected) --;
    }

    if(MIA(433, 80, 60, 60) && kp(VK_LBUTTON)) (*selected) = 0;
    if(MIA(505, 80, 60, 60) && kp(VK_LBUTTON)) (*selected) = 1;
    if(MIA(433, 153, 60, 60) && kp(VK_LBUTTON)) (*selected) = 2;
    if(MIA(505, 153, 60, 60) && kp(VK_LBUTTON)) (*selected) = 3;
    if(MIA(433, 224, 60, 60) && kp(VK_LBUTTON)) (*selected) = 4;
    if(MIA(505, 224, 60, 60) && kp(VK_LBUTTON)) (*selected) = 5;
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
        PT( 120, 185, gang.characters[selected].Height, gang.characters[selected].Height, 
               gang.characters[selected].WalkSpriteDC[(gang.characters[selected].WalkSpriteCnt++)%gang.characters[selected].WalkSpriteNum]);
}