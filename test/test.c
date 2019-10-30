#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>

#define Dbot_Y 84
#define Tbot_Y 45
#define Tbot_X 100
#define Startmessage_X 45
#define Startmessage_Y 3

HINSTANCE hInstance;
HWND hWnd;
HBITMAP MAP1, MAP2, MAP3;
HDC MAPDC1, MAPDC2, MAPDC3;
HDC hMemDC;

void SetConsoleView()
{
   system("mode con:cols=360 lines=40");
}


void GotoXY(int x, int y)
{
   COORD Pos;
   Pos.X = 2 * x;
   Pos.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void clearCursor()
{
   CONSOLE_CURSOR_INFO cc;
   cc.bVisible = 0;
   cc.dwSize = 1;
   SetConsoleCursorInfo(
      GetStdHandle(STD_OUTPUT_HANDLE), &cc);
}

void Cookie(int a, int b, int c, int d, int e, int f)
{
   while (1)
   {
      BitBlt(hMemDC, a, b, 100, 100, MAPDC1, 0, 0, SRCCOPY);
      BitBlt(hMemDC, c, d, 100, 100, MAPDC2, 0, 0, SRCCOPY);
      BitBlt(hMemDC, e, f, 100, 100, MAPDC3, 0, 0, SRCCOPY);
   }
   
}
void displayStart()
{
   hWnd = GetConsoleWindow();
   hMemDC = GetDC(hWnd);
   MAP1 = (HBITMAP)LoadImage(NULL,
         TEXT("0.bmp"),
         IMAGE_BITMAP,
         0,
         0,
         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(MAPDC1, MAP1);

   MAP2 = (HBITMAP)LoadImage(NULL,
         TEXT("1.bmp"),
         IMAGE_BITMAP,
         0,
         0,
         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(MAPDC2, MAP2);

   MAP3 = (HBITMAP)LoadImage(NULL,
         TEXT("2.bmp"),
         IMAGE_BITMAP,
         0,
         0,
         LR_LOADFROMFILE | LR_CREATEDIBSECTION);
   SelectObject(MAPDC3, MAP3);

   while (!kbhit())
   {
      GotoXY(0,0);
      printf("How to play\n");
      printf("Jump : ctrl\n");
      GotoXY(Startmessage_X, Startmessage_Y);
      printf(" _____  _____ ___  ___ _____  ______   __   __  _   _\n");
      GotoXY(Startmessage_X, Startmessage_Y + 1);
      printf("|  _  \\|_   _||  \\/  ||_   _| | ___ \\ |  | |  || \\ | |\n");
      GotoXY(Startmessage_X, Startmessage_Y + 2);
      printf("| | | |  | |  | .  . |  | |   | |_/ / |  | |  ||  \\| |\n");
      GotoXY(Startmessage_X, Startmessage_Y + 3);
      printf("| | | |  | |  | |\\/| |  | |   |    /  |  | |  || . ` |\n");
      GotoXY(Startmessage_X, Startmessage_Y + 4);
      printf("| |_/ | _| |_ | |  | | _| |_  | |\\  \\ |  |_|  || |\\  |\n");
      GotoXY(Startmessage_X, Startmessage_Y + 5);
      printf("|____/ |_____||_|  |_||_____| |_| \\__| \\_____/ |_| |_|\n");
      
      GotoXY(52, 80);
      printf("Press any key to start");
      Sleep(500);
      GotoXY(52, 80);
      printf("                             ");
      Cookie(400,300,800,300,1200,300);
   }

   system("cls");
}
int GetKeyDown()
{
   if (_kbhit() != 0)
   {
      return _getch();
   }
   return 0;
}

void DrawCH(int cute)
{   
   GotoXY(10, cute);
   static int legFlag = 1;   
   printf("5555555\n");
   GotoXY(10, cute + 1);
   printf("5555555\n");
   GotoXY(10, cute + 2);
   printf("5555555\n");
   GotoXY(10, cute + 3);
   printf("5555555\n");
   GotoXY(10, cute + 4);
   printf("5555555\n");
   

   
   
   if (legFlag)
   {
      /*다리가 접힘*/
      legFlag = 0;
   }
   else
   {
      /*다리가 펴짐*/
      legFlag = 1;
   }
}

void DrawTree(int treeX,int shape)
{
   switch (shape)
   {
   case 0:
      GotoXY(treeX, Tbot_Y);
      printf("");
   case 1:
      printf("");
   case 2:
      printf("");
   case 3:
      printf("");
   case 4:
      printf("");
   case 5:
      printf("");
   case 6:
      printf("");
   case 7:
      printf("");
   case 8:
      printf("");
   }
   
}


int main(void)
{
   SetConsoleView();
   
   int isJumping = 0;
   int isBottom = 1;
   const int gravity = 7;
   int dinoY = Dbot_Y;
   int treeX = Tbot_X;
   int score = 0;
   int shape = 0;
   displayStart();
   clearCursor();
   
   GotoXY(treeX, Tbot_Y + 2);
   while (1)
   {
      if (GetKeyDown() == 'e')
      {
         break;
      }
      if (GetAsyncKeyState(VK_CONTROL)&0x8000 && isBottom )
      {
         isJumping = 1;
         isBottom = 0;
      }
      if (isJumping)
      {
         dinoY -= gravity;
      }
      else
      {
         dinoY += gravity;
      }
      if (dinoY >= Dbot_Y)
      {

         dinoY = Dbot_Y;
         isBottom = 1;
      }
      if (dinoY <= 30)
      {
         isJumping = 0;
      }
         treeX -= 3;
   
      
      if (treeX <= 0)
      {
         treeX = Tbot_X;
      }
      shape = rand() % 9;
      DrawCH(dinoY);
      DrawTree(treeX, shape);
      Sleep(80);
      system("cls");
   }
   GotoXY(35, 22);
   printf(" _____                           _____\n");
   GotoXY(35, 23);
   printf("|  __ \\                         |  _  |\n");
   GotoXY(35, 24);
   printf("| |  \\/  __ _  _ __ ___    ___  | | | |__   __  ___  _ __ \n");
   GotoXY(35, 25);
   printf("| | __  / _` || '_ ` _ \\  / _ \\ | | | |\\ \\ / / / _ \\| '__|\n");
   GotoXY(35, 26);
   printf("| |_\\ \\| (_| || | | | | ||  __/ \\ \\_/ / \\ V / |  __/| |\n");
   GotoXY(35, 27);
   printf(" \\____/ \\__,_||_| |_| |_| \\___|  \\___/   \\_/   \\___||_|\n");
   GotoXY(35, 30);
   printf("Last Score = %d!!!!\n", score);
                                                         
   system("pause");
   return 0;

}

