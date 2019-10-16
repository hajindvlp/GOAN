#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

typedef struct {
    char name[101];
    int hp;
    int dg;
    int cost;
    int speed;
    HDC CharacterDC;
    HBITMAP CharacterSprite[101];
    int CharacterSpriteNum;
    int CharacterSpriteCnt;
    char shortcut;
    int BattleHp;
    int BattleDg;
    int BattleX;
    int BattleDead;
} Character;

typedef struct {
    int chracterNum = 0;
    Character characters[100];
    void (*upgrade)(int, int, int) = GangUpgrade;
} Gang;

Gang gang;

void GangUpgrade(int characterCode, int hpUp, int dgUp);