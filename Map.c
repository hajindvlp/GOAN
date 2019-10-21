#include "Map.h"

void MapSelect() {

    int selected = 0;
    
    printf("[*] MapSelect Function\n");

    system("cls");
    for(int i=0 ; i<map.Height ; i++) {
        for(int j=0 ; j<map.Width ; j++) {
            printf("%c", map.MapString[i][j]);
        }
        printf("\n");
    }

    while(1) {
        if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && selected+1 < map.countriesNum) { //left
            selected++;
            MapRender(selected);
        } else if(GetAsyncKeyState(VK_LEFT) & 0x8000 && selected > 0) {  // right 
            selected--;
            MapRender(selected);
        } else if(GetAsyncKeyState(VK_RETURN) & 0x8000) {
            startBattle(selected);
            break;
        } else if(GetAsyncKeyState('I') & 0x8000) {
            UpgradeSelect();
        } else if(getch() == 12) {
            BattleMain(selected);
            break;
        }
        // else if(GetAsyncKeyState('O') & 0x8000) {
        //     MapSelect();
        // }
    }
}

void MapRender(int selected) {
    int OldSelected = -1;
    printf("[*] MapRender Function\n");

    if(selected >= 1 && selected <= 5) {
        if(OldSelected != -1) {
            gotoxy(map.countries[OldSelected].MapY, map.countries[OldSelected].MapX-1);
            printf(" ");
            gotoxy(map.countries[OldSelected].MapY, map.countries[OldSelected].MapX+1);
            printf(" ");
        }
        gotoxy(map.countries[selected].MapY, map.countries[selected].MapX-1);
        printf("[");
        gotoxy(map.countries[selected].MapY, map.countries[selected].MapX+1);
        printf("]");
        map.MapString[map.countries[selected].MapY][map.countries[selected].MapX-1] = '[';
        map.MapString[map.countries[selected].MapY][map.countries[selected].MapX+1] = ']';
    }
}

void startBattle(int selected) {

}