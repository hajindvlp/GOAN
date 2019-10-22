#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <gdiplus.h>

void gotoxy(int x, int y);
int key_pressed(int key);
void PrintImage(HDC destDC, int sx, int sy, int dw, int dh, HDC originDC, int w, int h);
void UtilityInit();

BLENDFUNCTION bf;

#endif