#ifndef GANG_H
#define GANG_H

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
    int df;
    int cost;
    int ms;
    int as;

    char path[101];

    HDC CharacterWalkSpriteDC[101];
    HDC CharacterAttackSpriteDC[101];
    HDC CharacterDieSpriteDC[101];
    HBITMAP CharacterWalkSpriteMap[101];
    HBITMAP CharacterAttackSpriteMap[101];
    HBITMAP CharacterDieSpriteMap[101];
    int CharacterWalkSpriteNum;
    int CharacterWalkSpriteCnt;
    int CharacterAttackSpriteNum;
    int CharacterAttackSpriteCnt;
    int CharacterDieSpriteNum;
    int CharacterDieSpriteCnt;

    int BattleHp;
    int BattleDg;
    int BattleX;
    int BattleDead;
} Character;

typedef struct {
    int characterNum;
    Character characters[100];
} Gang;

typedef struct {
    int hp;
} Castle;

Gang gang;
int PlayerExp;

void GangUpgrade(int characterCode, int hpUp, int dgUp);

#endif