#include "Upgrade.h"

void UpgradeSelect() {

    int selected = 0;

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function\n");

    while(1) {
        UpgradeUpdate(&selected);
        UpgradeRender(selected);
        Sleep(200);
    }

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function Ended");
}

void UpgradeUpdate(int *selected) {
    gotoxy(39, 30);
    printf("[*] UpgradeUpdate Function");
    if(key_pressed('o')) {

    } 
    if(key_pressed(VK_RIGHT)) {
        (*selected) ++;
    }
    if(key_pressed(VK_LEFT)) {
        (*selected) --;
    }
}

void UpgradeRender(int selected) {
    gotoxy(39, 30);
    printf("[*] UpgradeRender Function %d selected", selected);
    
    for(int i=0 ; i<gang.characterNum ; i++)
    {
        if(selected == i) {
            PrintImage(ConsoleDC, 
                       (10+28)*(i), 10, 10+100+28*(i), 10+100, 
                       gang.characters[i].CharacterWalkSpriteDC[(gang.characters[i].CharacterWalkSpriteCnt++)%gang.characters[i].CharacterWalkSpriteNum],
                       100, 100);
        }
        else {
            PrintImage(ConsoleDC, 
                       (10+28)*(i), 10, 10+100+28*(i), 10+100, 
                       gang.characters[i].CharacterWalkSpriteDC[0],
                       100, 100);
        }
    }
}