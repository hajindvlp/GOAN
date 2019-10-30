#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>
#include <time.h>
 
HWND ConsoleWindow;
HINSTANCE ConsoleInstance;

HDC ConsoleDC, MenuUpgradeDC,  MenuMapDC,  BlankDC,  BattleBackgroundDC,  MenuSelectDC,  ArrowLeftDC,  ArrowRightDC ;
HBITMAP        MenuUpgradeMap, MenuMapMap, BlankMap, BattleBackgroundMap, MenuSelectMap, ArrowLeftMap, ArrowRightMap;

HDC AlphabetDC[27], NumberDC[10];
HBITMAP AlphabetMap[27], NumberMap[10];

// typedef struct {
//     HDC* DC;
//     HBITMAP* Map;
//     char* path;
// } Object;

typedef struct {
    char name[101];
    int hp;    // health point
    int df;    // defense
    int dg;    // damage 
    int cost;  // cost
    int ratio; // sumon rate
    int ms;    // move speed
    int as;    // attack speed

    int bd;    // battle is Dead
    int ba;    // 
    int bX;    // battle X coord

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

void UtilityInit();
void gotoxy(int x, int y);
int RR(int ratio);
int kp(int key);
int kpw(int key);
int GMX();
int GMY();
int MIA(int sx, int sy, int w, int h);
void HideCursor();
void LI(HDC* DC, HBITMAP* Map, char* path);
// void LO(Object object);
void PT(int sx, int sy, int w, int h, HDC originDC);
void PTB(int sx, int sy, int w, int h, HDC originDC);
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PrintBackground(int UMCode);

#endif