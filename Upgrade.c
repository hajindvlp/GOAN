#include "Upgrade.h"

void UpgradeSelect() {

    int selected = 0;

    while(1) {
        if(GetAsyncKeyState(VK_LEFT) & 0x8000 && selected+1 < gang.characterNum) { //left
            selected++;
            UpgradeRender(selected);
        } else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && selected > 0) {  // right 
            selected--;
            UpgradeRender(selected);
        } else if(GetAsyncKeyState('1')) { // upgrade Hp
            GangUpgrade(selected, 1, 0);
            UpgradeRender(selected);
        } else if(GetAsyncKeyState('2')) { // upgrade Dg
            GangUpgrade(selected, 0, 1);
            UpgradeRender(selected);
        }
    }
}

void UpgradeRender(int selected) {



}