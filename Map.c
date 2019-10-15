#include "Map.h"

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
                    if(selected+1 < map.countriesNum) selected++;
                    render(selected);
                    break;
            }
        } else if(getch() == '\n') {
            startBattle(selected);
        }
    }
}

void render(int selected) {

    

}