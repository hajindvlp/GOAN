#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>
 
HWND ConsoleWindow;
HINSTANCE ConsoleInstance;

HDC     ConsoleDC, MenuUpgradeDC,  MenuMapDC,  BlankDC,  BattleBackgroundDC,  BattleCharacterSelectBoxDC,  MenuSelectDC;
HBITMAP            MenuUpgradeMap, MenuMapMap, BlankMap, BattleBackgroundMap, BattleCharacterSelectBoxMap, MenuSelectMap;

HDC AlphabetDC[27], NumberDC[10];
HBITMAP AlphabetMap[27], NumberMap[10];


int BracketCoord[6][4];

// typedef struct {
//     HDC* DC;
//     HBITMAP* Map;
//     char* path;
// } Object;

typedef struct {
    char name[101];
    int hp;
    int dg;
    int df;
    int cost;
    int ms;
    int as;

    char path[101];

    HDC BattleIconDC, UpgradeIconDC;
    HBITMAP BattleIconMap, UpgradeIconMap;

    HDC WalkSpriteDC[101];
    HDC AttackSpriteDC[101];
    HDC DieSpriteDC[101];
    HBITMAP WalkSpriteMap[101];
    HBITMAP AttackSpriteMap[101];
    HBITMAP DieSpriteMap[101];

    int WalkSpriteNum;
    int WalkSpriteCnt;
    int AttackSpriteNum;
    int AttackSpriteCnt;
    int DieSpriteNum;
    int DieSpriteCnt;

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

void gotoxy(int x, int y);
int kp(int key);
int kpw(int key);
int GMX();
int GMY();
int MIA(int sx, int sy, int w, int h);
void HideCursor();
void LI(HDC* DC, HBITMAP* Map, char* path);
// void LO(Object object);
void UtilityInit();
void PT(int sx, int sy, int w, int h, HDC originDC);
void PTB(int sx, int sy, int w, int h, HDC originDC);
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PrintBackground(int UMCode);

#endif