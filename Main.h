#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <windows.h>

#include "Map.h"
#include "Upgrade.h"
#include "Battle.h"
#include "Player.h"
#include "Utility.h"

void MainInit();
void MainGame();
void MainUpdate();
void MainRender(int selected);

#endif