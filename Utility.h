#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>

#include "Battle.h"
 
HDC UpgradeDC, MapDC;
HBITMAP UpgradeMap, MapMap;

void gotoxy(int x, int y);
int key_pressed(int key);
void UtilityInit();
void PrintImage(int sx, int sy, int w, int h, HDC originDC);
void PrintBackground(int UMCode);

#endif