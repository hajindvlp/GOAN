#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "Gang.h"
#include "Battle.h"

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    char name;
    int MapX;
    int MapY;
    Gang enemy;
} Country;

typedef struct {
    int a[WIDTH+1][HEIGHT+1];
    int countriesNum;
    Country countries[10];
    char MapString;
} Map;

Map map;

void MapSelect();
void MapRender(int selected);
void startBattle(int selected);

#endif