#include "Battle.h"

void BattleMain() {
    BattleInit();
    while(1) {
        BattleUpdate();
        BattleKeyin();
        BattleRender();
        Sleep(1000/FPS);
    }
}

void BattleInit() {
    ConsoleInstance = GetModuleHandle(NULL);
    ConsoleWindow = GetConsoleWindow();
    ConsoleDC = GetDC(ConsoleWindow);

    BackgroundDC = CreateCompatibleDC(ConsoleDC);
    BackgroundMap = (HBITMAP) LoadImage(NULL, 
                                          TEXT("./resources/background.bmp"),
                                          IMAGE_BITMAP,
                                          0,
                                          0,
                                          LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    SelectObject(BackgroundDC, BackgroundMap);

    BattleRender();
}

void BattleUpdate() {
    for(int i=0 ; i<OutAllyCnt ; i++) {
        if(!OutAlly[i].BattleDead && OutAlly[i].BattleHp > 0) {
            if(!Collided) 
                OutAlly[i].BattleX += OutAlly[i].speed;
            OutAllyXMax = (OutAllyXMax > OutAlly[i].BattleX) ? OutAllyXMax : OutAlly[i].BattleX;
        } else {
            OutAlly[i].BattleDead = 1;
        }
    } 
    for(int i=0 ; i<OutEnemyCnt ; i++) {
        if(!OutEnemy[i].BattleDead && OutEnemy[i].BattleHp > 0 && OutEnemy[i].BattleX) {
            OutEnemy[i].BattleX -= OutEnemy[i].speed;
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
    for(int i=0 ; i< gang.characterNum ; i++) 
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
            BitBlt(ConsoleDC, OutAlly[i].BattleX, BattleGround+OutAlly[i].width, OutAlly[i].width, OutAlly[i].height, OutAlly[i].CharacterWalkSpriteDC[0], 0, 0, SRCCOPY);
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