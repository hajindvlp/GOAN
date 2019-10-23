#include "Upgrade.h"

int UpgradeSelect() {

    int selected = 0;

    PrintBackground(1);
    while(1) {
        if( UpgradeUpdate(&selected) )
            return 2;
        UpgradeRender(selected);
        Sleep(200);
    }    
}

int UpgradeUpdate(int *selected) {
    if(kp('O')) {
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
    
    for(int i=0 ; i<gang.characterNum ; i++)
    {
        if(selected == i) {
            PTIB( 20 + (20 + 100) * i, 100, 100, 100, 
                       gang.characters[i].CharacterWalkSpriteDC[(gang.characters[i].CharacterWalkSpriteCnt++)%gang.characters[i].CharacterWalkSpriteNum]);
        }
        else {
            PTIB( 20 + (20 + 100) * i, 100, 100, 100, 
                       gang.characters[i].CharacterWalkSpriteDC[0]);
        }
    }
}