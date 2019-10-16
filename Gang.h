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
    int width;
    int height;
    int speed;
    HDC CharacterWalkSprite[101];
    HDC CharacterAttackSprite[101];
    HBITMAP CharacterWalkSprite[101];
    HBITMAP CharacterAttackSprite[101];
    int CharacterSpriteWalkNum;
    int CharacterSpriteWalkCnt;
    int CharacterSpriteAttackNum;
    int CharacterSpriteAttackCnt;
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

typedef struct {
    int hp;
} Castle;

Gang gang;

void GangUpgrade(int characterCode, int hpUp, int dgUp);