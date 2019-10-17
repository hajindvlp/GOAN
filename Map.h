#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "Gang.h"
#include "Battle.h"

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

void MapSelect();
void MapRender(int selected);
void startBattle(int selected);

#endif