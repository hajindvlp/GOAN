#include <windows.h>
#include <stdio.h>

int main()
{
   HDC consoleDC, imageDC;
   HBITMAP imageMap;
   HWND consoleWindow;

   char filename[101] = "2.bmp";

   consoleWindow = GetConsoleWindow();
   consoleDC = GetDC(consoleWindow);
   imageDC = CreateCompatibleDC(consoleDC);
   imageMap = LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(imageDC,imageMap);

   BitBlt(consoleDC, 0, 0, 100, 100, imageDC, 0, 0, SRCCOPY);
   while(1);
}