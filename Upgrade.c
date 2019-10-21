#include "Upgrade.h"

void UpgradeSelect() {

    int selected = 0;

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function\n");

    while(1) {
        UpgradeUpdate(&selected);
        UpgradeRender(selected);
        gotoxy(39, 30);
    }

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function Ended");
}

void UpgradeUpdate(int *selected) {
    gotoxy(39, 30);
    printf("[*] UpgradeUpdate Function");
    if(kbhit()) {
        char key = getch();
        if(key == 'o') {
            printf("[*] pressed O");
        } else if(key == '\033') {
            printf("[*] pressed arrow key");
            getch();
            key = getch();
            if(key == 'C' && *selected+1 < gang.characterNum) {
                (*selected) ++;
            } else if(key =='D' && *selected-1 >= 0) {
                (*selected) --;
            }
        }
    }
}

void UpgradeRender(int selected) {
    gotoxy(39, 30);
    printf("[*] UpgradeRender Function %d selected", selected);

    BitBlt(ConsoleDC, 0, 0, 500, 400, gang.characters[0].CharacterWalkSpriteDC[0], 0, 0, SRCCOPY);
}