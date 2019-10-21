#include "Upgrade.h"

void UpgradeSelect() {

    gotoxy(39, 30);
    printf("[*] UpgradeSelect Function\n");

    while(1 && !UpgradeUpdate()) {
        UpgradeRender(selected);
    }
}

int UpgradeUpdate() {
    if(getch() == 'O') {
        MapSelect();
        return 1;
    } if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && selected+1 < gang.characterNum) {
        selected++;
    } if(GetAsyncKeyState(VK_LEFT) & 0x8000 && selected-1 >= 0) {
        selected--;
    }
    return 0;
}

void UpgradeRender(int selected) {
    gotoxy(39, 30);
    printf("[*] UpgradeRender Function");

    BitBlt(ConsoleDC, 0, 0, 500, 400, gang.characters[0].CharacterWalkSpriteDC[0], 0, 0, SRCCOPY);
}