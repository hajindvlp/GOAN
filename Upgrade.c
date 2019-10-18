#include "Upgrade.h"

void UpgradeSelect() {

    int selected = 0;

    printf("[*] UpgradeSelect Function\n");

    while(1) {
        printf("[*] Selected Var : %d\n", selected);
        if(GetAsyncKeyState(VK_LEFT) & 0x8000 && selected+1 < gang.characterNum) { //left
            selected++;
            UpgradeRender(selected);
        } else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && selected > 0) {  // right 
            selected--;
            UpgradeRender(selected);
        } else if(GetAsyncKeyState('1') & 0x8000) { // upgrade Hp
            GangUpgrade(selected, 1, 0);
            UpgradeRender(selected);
        } else if(GetAsyncKeyState('2') & 0x8000) { // upgrade Dg
            GangUpgrade(selected, 0, 1);
            UpgradeRender(selected);
        } else if(GetAsyncKeyState('I') & 0x8000) {
            UpgradeSelect();
        } else if(GetAsyncKeyState('O') & 0x8000) {
            MapSelect();
        }
    }
}

void UpgradeRender(int selected) {
    printf("[*] UpgradeRender Function\n");
}