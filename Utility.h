#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>
#include <time.h>

void UtilityInit();
void Video();
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
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PN(int sx, int sy, int w, int h, int number);
void PM(char *path);
void PrintBackground(int UMCode);
int abs(int x);
 
HWND ConsoleWindow;
HINSTANCE ConsoleInstance;
HDC ConsoleDC;

HDC     StartScreenDC,  MenuSelectDC;
HBITMAP StartScreenMap, MenuSelectMap;

HDC     MenuUpgradeDC , ToMapDC[3];
HBITMAP MenuUpgradeMap, ToMapMap[3];

HDC     MenuMapDC,  BracketLeftDC, BracketRightDC  , ToUpgradeDC[3],  ConqueredDC;
HBITMAP MenuMapMap, BracketLeftMap, BracketRightMap, ToUpgradeMap[3], ConqueredMap;

HDC     BattleBackgroundDC,  CoinDC, BlackDC,  
        LoseScreenDC, LoseMapDC, LoseStoreDC, LoseRetryDC,
        WinScreenDC, WinMapDC, WinStoreDC;
HBITMAP BattleBackgroundMap, CoinMap, BlackMap, 
        LoseScreenMap, LoseMapMap, LoseStoreMap, LoseRetryMap,
        WinScreenMap, WinMapMap, WinStoreMap;

HDC     NumberRawDC;
HBITMAP NumberRawMap;

HDC     AlphabetDC[27],  NumbersDC[10];
HBITMAP AlphabetMap[27], NumbersMap[10];

BLENDFUNCTION BattleBackBldFunc;

typedef struct {

    char name[101];
    int hp;    // health point
    int df;    // defense
    int dg;    // damage 

    int as;    // attack speed
    int ms;    // move speed
    int sc;    // summon cool time
    int cost;  // cost
    int ratio; // sumon rate

    int Width;
    int Height;

    int bd;    // battle is Dead
    int bw;    // battle is Walking
    int ba;    // battle is Attacking
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
    int x, y;
    int vx, vy;
    int isRender, fcnt;
} Coin;

typedef struct {
    int characterNum;
    Character characters[100];
} Gang;

typedef struct {
    int hp;
} Castle;

Gang gang;
int PlayerExp;

#endif