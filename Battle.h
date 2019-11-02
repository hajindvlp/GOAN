#ifndef BATTLE_H
#define BATTLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

#include "Map.h"
#include "Utility.h"
#include "Player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GROUND 590
#define FPS 30

int BattleMain(int EnemyCode);
void BattleInit();
int BattleUpdate();
void BattleKeyin();
void BattleRender();
int RenderLoose();
int RenderWin();

Gang Enemy;
Gang Ally;
Castle AllyCastle, EnemyCastle;

Character OutAlly[10000];
Character OutEnemy[10000];
int OutAllyCnt;
int OutEnemyCnt;

Coin coin[101];
int coinNum;

int ScreenX;
int Cost;
int ECode;
int fcnt;

#endif