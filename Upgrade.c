#include "Upgrade.h"

int UpgradeSelect() {
    
    int selected = 0;

    PrintBackground(1);
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
    if(GMX() >= 100 && GMX() <= 196 && GMY() >= 14 && GMY() <= 47 && kp(VK_LBUTTON)) {
        return 1;
    }
    if(kp(VK_RIGHT)) {
        (*selected) ++;
    }
    if(kp(VK_LEFT)) {
        (*selected) --;
    }
    return 0;
}

void UpgradeRender(int selected) {
    // printf("%d %d\n", GMX(), GMY());
    for(int i=0 ; i<gang.characterNum ; i++)
    {
        if(selected == i) {
            PTB( 20 + (20 + 100) * i, 100, 100, 100, 
                       gang.characters[i].CharacterDieSpriteDC[(gang.characters[i].CharacterDieSpriteCnt++)%gang.characters[i].CharacterDieSpriteNum]);
        }
        else {
            PTB( 20 + (20 + 100) * i, 100, 100, 100, 
                       gang.characters[i].CharacterWalkSpriteDC[0]);
        }
    }
}