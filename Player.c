#include "Player.h"

void Load() {
    printf("[*] Load Function\n");
    ConfigureFile = fopen("./resources/DATA", "r+");
    if(ConfigureFile != NULL) {
        printf("[*] Reading Config File\n");

        fscanf(ConfigureFile, "%d", &PlayerExp); // player exp

        fscanf(ConfigureFile, "%d", &gang.characterNum);
        for(int i=0 ; i<gang.characterNum ; i++) {

            fscanf(ConfigureFile, "%s", gang.characters[i].name);
            fscanf(ConfigureFile, "%d", &gang.characters[i].hp);
            fscanf(ConfigureFile, "%d", &gang.characters[i].dg);
            fscanf(ConfigureFile, "%d", &gang.characters[i].cost);
            fscanf(ConfigureFile, "%d", &gang.characters[i].width);
            fscanf(ConfigureFile, "%d", &gang.characters[i].height);
            fscanf(ConfigureFile, "%d", &gang.characters[i].speed);
            fscanf(ConfigureFile, " %c", &gang.characters[i].shortcut);

            sprintf(gang.characters[i].path, "./resources/%s/sprites", gang.characters[i].name);

            fscanf(ConfigureFile, "%d", &gang.characters[i].CharacterWalkSpriteNum);
            fscanf(ConfigureFile, "%d", &gang.characters[i].CharacterAttackSpriteNum);

            for(int j=0 ; j<gang.characters[i].CharacterWalkSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Walk/%d.bmp", gang.characters[i].path, j);

                gang.characters[i].CharacterWalkSpriteDC[j] = CreateCompatibleDC(ConsoleDC);
                gang.characters[i].CharacterWalkSpriteMap[j] = (HBITMAP) LoadImage(NULL,
                                                                     TEXT(path),
                                                                     IMAGE_BITMAP,
                                                                     0,
                                                                     0,
                                                                     LR_LOADFROMFILE | LR_CREATEDIBSECTION);
                SelectObject(gang.characters[i].CharacterWalkSpriteDC[j], gang.characters[i].CharacterWalkSpriteMap[j]);
            }

            for(int j=0 ; j<gang.characters[i].CharacterAttackSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Attack/%d.bmp", gang.characters[i].path, j);

                gang.characters[i].CharacterAttackSpriteDC[j] = CreateCompatibleDC(ConsoleDC);
                gang.characters[i].CharacterAttackSpriteMap[j] = (HBITMAP) LoadImage(NULL,
                                                                     TEXT(path),
                                                                     IMAGE_BITMAP,
                                                                     0,
                                                                     0,
                                                                     LR_LOADFROMFILE | LR_CREATEDIBSECTION);
                SelectObject(gang.characters[i].CharacterAttackSpriteDC[j], gang.characters[i].CharacterAttackSpriteMap[j]);
            }
        }

        fscanf(ConfigureFile, "%d %d", &AllyCastle.hp, &EnemyCastle.hp);
    }

    fscanf(ConfigureFile, "%d", &map.countriesNum);
    fscanf(ConfigureFile, "%d %d", &map.Height, &map.Width);
    for(int i=0 ; i<map.Height ; i++) {
        char tmp[301];
        fscanf(ConfigureFile, "%s", tmp);
        for(int j=0 ; j<map.Width ; j++) {
            map.MapString[i][j] = tmp[j];
        }
    }
    for(int i=0 ; i<map.countriesNum ; i++) {
        fscanf(ConfigureFile, "%d %d %c", &map.countries[i].MapX, &map.countries[i].MapY, &map.countries[i].name);
    }

    BackgroundDC = CreateCompatibleDC(ConsoleDC);
    BackgroundMap = (HBITMAP) LoadImage(NULL, 
                                          TEXT("./resources/background.bmp"),
                                          IMAGE_BITMAP,
                                          0,
                                          0,
                                          LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(BackgroundDC, BackgroundMap);
}

void Debug() {
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