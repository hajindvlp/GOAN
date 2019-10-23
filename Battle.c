#include "Battle.h"

void BattleMain(int EnemyCode) {
    ECode = EnemyCode;
    BattleInit();
    while(1) {
        BattleUpdate();
        BattleKeyin();
        BattleRender();
        Sleep(1000/FPS);
    }
}

void BattleInit() {
    ScreenX = 0;
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

    if(GMX() <= 20 && ScreenX >= 3) ScreenX -= (20-GMX());
    else if(GMX() >= 380 && ScreenX < 1292-500 - 3) ScreenX += (GMX()-380); 
    if(ScreenX < 0) ScreenX = 0;
    else if(ScreenX > 1292-500) ScreenX = 1292-500;

    // char tmp = getch();
    // for(int i=0 ; i< gang.characterNum ; i++) 
    //     if(gang.characters[i].shortcut == tmp && OutAllyCnt < 100) {
    //         OutAlly[OutAllyCnt] = gang.characters[i];
    //         OutAlly[OutAllyCnt].BattleHp = OutAlly[OutAllyCnt].hp;
    //         OutAlly[OutAllyCnt].BattleDg = OutAlly[OutAllyCnt].dg;
    //         OutAlly[OutAllyCnt].BattleX = 30; // Ally castle Entrence
    //         OutAlly[OutAllyCnt].BattleDead = 0;
    //         OutAllyCnt++;
    //     }
}

void BattleRender() {
    // Render Background

    PIO(0, 0, ScreenX, 0, 500, 400, BattleBackgroundDC);

    // Render Allys

    // Render Enemy

}