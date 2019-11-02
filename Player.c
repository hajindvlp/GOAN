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
            fscanf(ConfigureFile, "%d", &gang.characters[i].sc);

            fscanf(ConfigureFile, "%d", &gang.characters[i].Width);
            fscanf(ConfigureFile, "%d", &gang.characters[i].Height);

            fscanf(ConfigureFile, "%d", &gang.characters[i].cost);

            sprintf(gang.characters[i].path, "./resources/%s/sprites", gang.characters[i].name);

            fscanf(ConfigureFile, "%d", &gang.characters[i].WalkSpriteNum);
            fscanf(ConfigureFile, "%d", &gang.characters[i].AttackSpriteNum);
            fscanf(ConfigureFile, "%d", &gang.characters[i].DieSpriteNum);

            for(int j=0 ; j<gang.characters[i].WalkSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Walk/%d.bmp", gang.characters[i].path, j);
                gotoxy(39, 30);

                LI(&gang.characters[i].WalkSpriteDC[j], 
                   &gang.characters[i].WalkSpriteMap[j],
                   path);
            }

            for(int j=0 ; j<gang.characters[i].AttackSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Attack/%d.bmp", gang.characters[i].path, j);

                LI(&gang.characters[i].AttackSpriteDC[j], 
                   &gang.characters[i].AttackSpriteMap[j],
                   path);
            }

            for(int j=0 ; j<gang.characters[i].DieSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Die/%d.bmp", gang.characters[i].path, j);

                LI(&gang.characters[i].DieSpriteDC[j], 
                   &gang.characters[i].DieSpriteMap[j],
                   path);
            }
            
            char path[101];
            sprintf(path, "./resources/%s/BattleIcon.bmp", gang.characters[i].name);
            LI(&gang.characters[i].BattleIconDC,
               &gang.characters[i].BattleIconMap,
               path);

            sprintf(path, "./resources/%s/UpgradeIcon.bmp", gang.characters[i].name);
            LI(&gang.characters[i].UpgradeIconDC,
               &gang.characters[i].UpgradeIconMap,
               path);
        }
    }
}

void EnemyLoad(int Ecode) {
    char FileName[101];
    sprintf(FileName, "./resources/STAGE%d", Ecode);
    ConfigureFile = fopen(FileName, "r+");

    if(ConfigureFile != NULL) {
        fscanf(ConfigureFile, "%d", &AllyCastle.hp);
        fscanf(ConfigureFile, "%d", &EnemyCastle.hp);
        fscanf(ConfigureFile, "%d", &Enemy.characterNum);

        for(int i=0 ; i<Enemy.characterNum ; i++) {
            
            fscanf(ConfigureFile, "%s", Enemy.characters[i].name);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].dg);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].df);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].hp);
            
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].as);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].ms);

            fscanf(ConfigureFile, "%d", &Enemy.characters[i].Width);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].Height);

            fscanf(ConfigureFile, "%d", &Enemy.characters[i].ratio);

            sprintf(Enemy.characters[i].path, "./resources/%s/sprites", Enemy.characters[i].name);

            fscanf(ConfigureFile, "%d", &Enemy.characters[i].WalkSpriteNum);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].AttackSpriteNum);
            fscanf(ConfigureFile, "%d", &Enemy.characters[i].DieSpriteNum);

            for(int j=0 ; j<Enemy.characters[i].WalkSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Walk/%d.bmp", Enemy.characters[i].path, j);
                gotoxy(39, 30);

                LI(&Enemy.characters[i].WalkSpriteDC[j], 
                   &Enemy.characters[i].WalkSpriteMap[j],
                   path);
            }

            for(int j=0 ; j<Enemy.characters[i].AttackSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Attack/%d.bmp", Enemy.characters[i].path, j);

                LI(&Enemy.characters[i].AttackSpriteDC[j], 
                   &Enemy.characters[i].AttackSpriteMap[j],
                   path);
            }

            for(int j=0 ; j<Enemy.characters[i].DieSpriteNum ; j++) {
                char path[101];
                sprintf(path, "%s/Die/%d.bmp", Enemy.characters[i].path, j);

                LI(&Enemy.characters[i].DieSpriteDC[j], 
                   &Enemy.characters[i].DieSpriteMap[j],
                   path);
            }

        }
    }

}

void Debug() {
    for(int i=0 ; i<gang.characterNum ; i++) {
        printf("%d %d %d\n", gang.characters[i].WalkSpriteNum, gang.characters[i].AttackSpriteNum, gang.characters[i].DieSpriteNum);
    }
    getch();
}

void Save() {

}