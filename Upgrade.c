#include "Upgrade.h"

int UpgradeSelect() {

    int selected = 0;

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function\n");

    PrintBackground(1);
    while(1) {
        if( UpgradeUpdate(&selected) )
            return 2;
        UpgradeRender(selected);
        Sleep(200);
    }

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function Ended");
    
}

int UpgradeUpdate(int *selected) {
    gotoxy(39, 30);
    printf("[*] UpgradeUpdate Function");
    if(key_pressed('O')) {
        gotoxy(40, 29);
        printf("[*] O key pressed");
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
    gotoxy(39, 30);
    printf("[*] UpgradeRender Function %d selected", selected);
    
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