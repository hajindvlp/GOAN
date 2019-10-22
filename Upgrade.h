#ifndef UPGRADE_H
#define UPGRADE_H

#include <stdio.h>
#include <conio.h>
#include "Player.h"
#include "Gang.h"
#include "Battle.h"

void UpgradeSelect();
void UpgradeUpdate(int *selected);
void UpgradeRender(int selected);

int x, y;

#endif