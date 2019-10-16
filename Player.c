#include "Player.h"

void Load() {
    ConfigureFile = fopen("./resources/DATA", "r+");
    if(ConfigureFile != NULL) {

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
                sprintf(path, "%s/Walk/%d.bmp", gang.characters[i].path, j);

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
    
    ConsoleInstance = GetModuleHandle(NULL);
    ConsoleWindow = GetConsoleWindow();
    ConsoleDC = GetDC(ConsoleWindow);

    BackgroundDC = CreateCompatibleDC(ConsoleDC);
    BackgroundMap = (HBITMAP) LoadImage(NULL, 
                                          TEXT("./resources/background.bmp"),
                                          IMAGE_BITMAP,
                                          0,
                                          0,
                                          LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(BackgroundDC, BackgroundMap);
}

void Save() {

}