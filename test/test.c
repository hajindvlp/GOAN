#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 170
#define HEIGHT 45
#define UP 72
#define DOWN 80
#define ENTER 13

#include <windows.h>
#include <stdio.h>

#pragma comment(lib, "Msimg32.lib")

HDC consoleDC, backgroundDC, startpageDC, arrowDC;
HBITMAP backgroundMap, startpageMap, arrowMap;
HWND consoleWindow;

void printBackground()
{
   backgroundDC = CreateCompatibleDC(consoleDC);
   backgroundMap = LoadImage(NULL, TEXT("C:\\resources\\background.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(backgroundDC, backgroundMap);

   BitBlt(consoleDC, 0, 0, 847, 440, backgroundDC, 0, 0, SRCCOPY);
}

void printStartpage()
{
   startpageDC = CreateCompatibleDC(consoleDC);
   startpageMap = LoadImage(NULL, TEXT("C:\\resources\\startpage.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(startpageDC, startpageMap);

   BitBlt(consoleDC, 0, 0, 1359, 854, startpageDC, 0, 0, SRCCOPY);
}

void printArrow(int x, int y)
{
   arrowDC = CreateCompatibleDC(consoleDC);
   arrowMap = LoadImage(NULL, TEXT("C:\\resources\\arrow.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(arrowDC, arrowMap);

   //TransparentBlt(consoleDC, x, y, 1359, 854, arrowDC, 0, 0, 1359, 854, RGB(255, 0, 255));
   BitBlt(consoleDC, x, y, 1359, 854, arrowDC, 0, 0, SRCCOPY);
}


void clearCursor()
{
   CONSOLE_CURSOR_INFO cc;
   cc.bVisible = FALSE;
   cc.dwSize = 1;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cc);
}

int main() {

   consoleWindow = GetConsoleWindow();
   consoleDC = GetDC(consoleWindow);
   printArrow();
}