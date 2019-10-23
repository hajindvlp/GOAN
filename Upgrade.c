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
    if(key_pressed('O')) {
        return 1;
    } 
    if(key_pressed(VK_RIGHT)) {
        (*selected) ++;
    }
    if(key_pressed(VK_LEFT)) {
        (*selected) --;
    }
    return 0;
}

void UpgradeRender(int selected) {
    
    for(int i=0 ; i<gang.characterNum ; i++)
    {
        if(selected == i) {
            PTIB( 30 + (30 + 40) * i, 100, 100, 100, 
                       gang.characters[i].CharacterWalkSpriteDC[(gang.characters[i].CharacterWalkSpriteCnt++)%gang.characters[i].CharacterWalkSpriteNum]);
        }
        else {
            PTIB( 30 + (30 + 40) * i, 100, 100, 100, 
                       gang.characters[i].CharacterWalkSpriteDC[0]);
        }
    }
}