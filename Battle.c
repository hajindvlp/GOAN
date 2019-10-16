#include "Battle.h"

void BattleMain() {
    BattleInit();
    while(1) {
        BattleUpdate();
        BattleKeyin();
        BattleRener();
        Sleep(1000/FPS);
    }
}

void BattleInit() {
    ConsoleInstance = GetModuleHandle(NULL);
    ConsoleWindow = GetConsoleWindow();
    ConsoleDC = GetDC(ConsoleWindow);

    BackgroundDC = CreateCompatibleDC(ConsoleDC);
    BackgroundImage = (HBITMAP) LoadImage(NULL, 
                                          TEXT("./resources/background.bmp"),
                                          IMAGE_BITMAP,
                                          0,
                                          0,
                                          LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectOject(BackgroundDC, BackgroundImage);

    BattleRender();
}

void BattleUpdate() {
    for(i=0 ; i<OutAllyCnt ; i++) {
        if(!OutAlly[i].BattleDead && OutAlly[i].BattleHp > 0) {
            if(!Collided) 
                OutAlly[i].BattleX += OutAlly[i].speed;
            OutAllyXMax = (OutAllyXMax > OutAllay[i].BattleX) ? OutAllyXMax : OutAllay[i].BattleX;
        } else {
            OutAlly[i].BattleDead = 1;
        }
    } 
    for(i=0 ; i<OutEnemyCnt ; i++) {
        if(!OutEnemy[i].BattleDead && OutEnemy[i].BattleHp > 0 && OutEnemy[i].BattleX) {
            OutEnemy[i].BattleY -= OutEnemy[i].speed;
        } else {
            OutEnemy[i].BattleDead = 1;
        }
    }

    // collision check Ally<->Enemy / Ally<->EnemyCastle / Enemy<->AllyCastle

    // attack
    
    // Sumon Enemy randomly
}

void BattleKeyin() {
    char tmp = getch();
    for(i=0 ; i< gang.characterNum ; i++) 
        if(gang.characters[i].shortcut == tmp && OutAllyCnt < 100) {
            OutAlly[OutAllyCnt] = gang.characters[i];
            OutAlly[OutAllyCnt].BattleHp = OutAlly[OutAllyCnt].hp;
            OutAlly[OutAllyCnt].BattleDg = OutAlly[OutAllyCnt].dg;
            OutAlly[OutAllyCnt].BattleX = 30; // Ally castle Entrence
            OutAlly[OutAllyCnt].BattleDead = 0;
            OutAllyCnt++;
        }
}

void BattleRender() {
    // Render Background
    BitBlt(ConsoleDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BackgroundDC, 0, 0, SRCCOPY);

    // Render Allys
    for(int i=0 ; i<OutAllyCnt ; i++) 
        if(!OutAlly[i].BattleDead) {
            BitBlt(ConsoleDC, OutAlly[i].BattleX, Ground+OutAlly[i].width, 0, 0, SRCCOPY);
        }

    // Render Enemy
}

void HideCursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}