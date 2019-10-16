#ifndef GANG_H
#define GANG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include "Player.h"

typedef struct {
    char name[101];
    int hp;
    int dg;
    int cost;
    int width;
    int height;
    int speed;
    HDC CharacterWalkSpriteDC[101];
    HDC CharacterAttackSpriteDC[101];
    HBITMAP CharacterWalkSpritemMap[101];
    HBITMAP CharacterAttackSpritemMap[101];
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
    int characterNum;
    Character characters[100];
} Gang;

typedef struct {
    int hp;
} Castle;

Gang gang;

void GangUpgrade(int characterCode, int hpUp, int dgUp);

#endif