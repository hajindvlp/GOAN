#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>

#include "Battle.h"
 
HWND ConsoleWindow;
HINSTANCE ConsoleInstance;

HDC     ConsoleDC, MenuUpgradeDC,  MenuMapDC,  BlankDC,  BattleBackgroundDC;
HBITMAP            MenuUpgradeMap, MenuMapMap, BlankMap, BattleBackgroundMap;

void gotoxy(int x, int y);
int kp(int key);
int kpw(int key);
int GMX();
int GMY();
void HideCursor();
void LI(HDC* DC, HBITMAP* Map, char* path);
void UtilityInit();
void PTI(int sx, int sy, int w, int h, HDC originDC);
void PTIB(int sx, int sy, int w, int h, HDC originDC);
void PIO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PrintBackground(int UMCode);

#endif