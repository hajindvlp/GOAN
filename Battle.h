#ifndef BATTLE_H
#define BATTLE_H

#include "Map.h"
#include "Utility.h"
#include "Player.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

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


int ECode;

Character OutAlly[10000];
Character OutEnemy[10000];
int OutAllyCnt;
int OutEnemyCnt;

int ScreenX;
int Cost;

Coin coin[101];
int coinNum;

int fcnt;

Gang Enemy;
Gang Ally;
Castle AllyCastle, EnemyCastle;

int BattleGround;

#endif