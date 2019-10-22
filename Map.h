#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "Gang.h"
#include "Battle.h"
#include "Utility.h"
#include "Upgrade.h"

HDC MapDC;

typedef struct {
    char name;
    int MapX;
    int MapY;
    Gang enemy;
} Country;

typedef struct {
    int Width;
    int Height;
    int countriesNum;
    Country countries[10];
    char MapString[400][400];
} Map;

Map map;

HDC MapDC;
HBITMAP MapMap;

void MapInit();
int MapSelect();
void MapRender(int selected);
void startBattle(int selected);

#endif