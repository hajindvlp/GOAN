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

    // collision check

    // attack
    
    // Sumon Enemy randomly
}

void BattleKeyin() {
    char tmp = getch();
    for(i=0 ; i< gang.characterNum ; i++) 
        if(gang.characters[i].shortcut == tmp && OutAllyCnt < 100) 
        {
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

    // Render Allys

    // Render Enemy
}

void HideCursor() {
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}