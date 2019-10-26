#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "Battle.h"
#include "Upgrade.h"
#include "Utility.h"

HDC MapDC;

typedef struct {
    char name;
    int MapX;
    int MapY;
    Gang enemy;
} Country;

typedef struct {
    int countriesNum;
    Country countries[10];
} Map;

Map map;
int oldSelected;
int BracketCoord[6][4];
int EnemyCoord[6][4];

HDC MapDC, BracketLeftDC, BracketRightDC;
HBITMAP MapMap, BracketLeftMap, BracketRightMap;

void MapInit();
int MapSelect();
int MapUpdate();
void MapRender(int selected);
void startBattle(int selected);

#endif