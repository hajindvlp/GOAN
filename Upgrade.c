#include "Upgrade.h"

void UpgradeSelect() {

    int selected = 0;

    while(1) {
        if(getch() == '\033') {
            getch();
            switch(getch()) {
                case 'C': // right
                    if(selected > 0) selected--;
                    UpgradeRender(selected);
                    break;
                case 'D': // left
                    if(selected+1 < gang.characterNum) selected++;
                    UpgradeRender(selected);
                    break;
            }
        } else if(getch() == '1') { // upgrade Hp
            GangUpgrade(selected, 1, 0);
            UpgradeRender(selected);
        } else if(getch() == '2') { // upgrade Dg
            GangUpgrade(selected, 0, 1);
            UpgradeRender(selected);
        }
    }
}

void UpgradeRender(int selected) {



}