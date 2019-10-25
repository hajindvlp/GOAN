#include "Player.h"

void Load() {
    ConfigureFile = fopen("./resources/DATA", "r+");

    if(ConfigureFile != NULL) {

        fscanf(ConfigureFile, "%d", &PlayerExp); // player exp

        fscanf(ConfigureFile, "%d", &gang.characterNum);
        for(int i=0 ; i<gang.characterNum ; i++) {

            fscanf(ConfigureFile, "%s", gang.characters[i].name);
            fscanf(ConfigureFile, "%d", &gang.characters[i].dg);
            fscanf(ConfigureFile, "%d", &gang.characters[i].df);
            fscanf(ConfigureFile, "%d", &gang.characters[i].hp);
            fscanf(ConfigureFile, "%d", &gang.characters[i].as);
            fscanf(ConfigureFile, "%d", &gang.characters[i].ms);
            fscanf(ConfigureFile, "%d", &gang.characters[i].cost);

            sprintf(gang.characters[i].path, "./resources/%s/sprites", gang.characters[i].name);

            fscanf(ConfigureFile, "%d", &gang.characters[i].CharacterWalkSpriteNum);
            fscanf(ConfigureFile, "%d", &gang.characters[i].CharacterAttackSpriteNum);
            fscanf(ConfigureFile, "%d", &gang.characters[i].CharacterDieSpriteNum);

            for(int j=0 ; j<gang.characters[i].CharacterWalkSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Walk/%d.bmp", gang.characters[i].path, j);
                gotoxy(39, 30);

                LI(&gang.characters[i].CharacterWalkSpriteDC[j], 
                   &gang.characters[i].CharacterWalkSpriteMap[j],
                   path);
            }

            for(int j=0 ; j<gang.characters[i].CharacterAttackSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Attack/%d.bmp", gang.characters[i].path, j);

                LI(&gang.characters[i].CharacterAttackSpriteDC[j], 
                   &gang.characters[i].CharacterAttackSpriteMap[j],
                   path);
            }

            for(int j=0 ; j<gang.characters[i].CharacterDieSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Die/%d.bmp", gang.characters[i].path, j);

                LI(&gang.characters[i].CharacterDieSpriteDC[j], 
                   &gang.characters[i].CharacterDieSpriteMap[j],
                   path);
            }
        }

        // fscanf(ConfigureFile, "%d %d", &AllyCastle.hp, &EnemyCastle.hp);

        // fscanf(ConfigureFile, "%d", &map.countriesNum);
        // for(int i=0 ; i<map.countriesNum ; i++) {
        //     fscanf(ConfigureFile, "%d %d", &map.countries[i].MapX, &map.countries[i].MapY);
        // }
    }
    // Debug();
}

void Debug() {
    gotoxy(10, 25);
    printf("%d\n", PlayerExp); // player exp

    printf("%d\n", gang.characterNum);
    for(int i=0 ; i<gang.characterNum ; i++) {
        printf("%s\n", gang.characters[i].name);
        printf("%d\n", gang.characters[i].hp);
        printf("%d\n", gang.characters[i].dg);
        printf("%d\n", gang.characters[i].cost);
        printf("%d\n", gang.characters[i].width);
        printf("%d\n", gang.characters[i].height);
        printf("%d\n", gang.characters[i].speed);
        printf("%c\n", gang.characters[i].shortcut);
        printf("%d\n", gang.characters[i].CharacterWalkSpriteNum);
        printf("%d\n", gang.characters[i].CharacterAttackSpriteNum);
    }
}

void Save() {

}