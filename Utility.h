#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>

#include "Battle.h"
 
HDC MenuUpgradeDC, MenuMapDC, BlankDC;
HBITMAP MenuUpgradeMap, MenuMapMap, BlankMap;

void gotoxy(int x, int y);
int key_pressed(int key);
void UtilityInit();
void PTI(int sx, int sy, int w, int h, HDC originDC);
void PTIB(int sx, int sy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PrintBackground(int UMCode);

#endif