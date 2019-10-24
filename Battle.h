#ifndef BATTLE_H
#define BATTLE_H

#include "Map.h"
#include "Gang.h"
#include "Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 200
#define FPS 30

void BattleMain(int EnemyCode);
void BattleInit();
void BattleUpdate();
void BattleKeyin();
void BattleRender();
void HideCursor();

int ECode;
Character OutAlly[101];
Character OutEnemy[101];
int OutAllyCnt;
int OutEnemyCnt;
int OutAllyXMax;
int OutEnemyXMax;
int Collided;

int ScreenX;

Gang Enemy;
Gang Ally;
Castle AllyCastle, EnemyCastle;

int BattleGround;

#endif