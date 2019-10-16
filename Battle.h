#include "Map.h"
#include "Gang.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 200
#define FPS 30

void BattleInit();
void BattleMain();
void BattleUpdate();
void BattleKeyin();
void BattleRender();
void HideCursor();

HWND ConsoleWindow;
HDC ConsoleDC, BufferDC;
HINSTANCE ConsoleInstance;
HBITMAP BufferMap;

HDC BackgroundDC;
HBITMAP BackgroundMap;

Character OutAlly[101];
Character OutEnemy[101];
int OutAllyCnt;
int OutEnemyCnt;
int OutAllyXMax;
int OutEnemyXMax;
int Collided;

Gang enemy;
Castle AllyCastle, EnemyCastle;