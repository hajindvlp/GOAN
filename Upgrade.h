#ifndef UPGRADE_H
#define UPGRADE_H

#include <stdio.h>
#include <conio.h>

#include "Player.h"
#include "Battle.h"

int UpgradeSelect();
void UpgradeInit();
int UpgradeUpdate(int *selected);
void UpgradeRender(int selected);

int x, y;
int ToMapCnt;

typedef struct {
    int sx, sy, w, h;
} UpgradeCharacter;

UpgradeCharacter UC[6];

#endif