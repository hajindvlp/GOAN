#include "Upgrade.h"

void select() {

    int selected = 0;

    while(1) {
        if(getch() == '\033') {
            getch();
            switch(getch()) {
                case C: // right
                    if(selected > 0) selected--;
                    render(selected);
                    break;
                case D: // left
                    if(selected+1 < gang.chracterNum) selected++;
                    render(selected);
                    break;
            }
        } else if(getch() == '1') { // upgrade Hp
            Upgrade(selected, 1, 0);
            render(selected);
        } else if(getch() == '2') { // upgrade Dg
            Upgrade(selected, 0, 1);
            render(selected);
        }
    }
}

void render(int selected) {



}