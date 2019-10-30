#include "Battle.h"

void BattleMain(int EnemyCode) {
    ECode = EnemyCode;
    BattleInit();
    while(1) {
        fcnt++;
        BattleUpdate();
        BattleKeyin();
        BattleRender();
        Sleep(1000/FPS);
    }
}

void BattleInit() {

    ScreenX = 0;

    OutAllyCnt = 0;
    OutEnemyCnt = 0;

    fcnt = 0;

    Cost = 100;

    Ally = gang;
    EnemyLoad(ECode);
}

void BattleUpdate() {

    // refresh frame cound for int overflow
    fcnt = fcnt%1110;

    // move characters & check characters health
    for(int i=0 ; i<OutAllyCnt  ; i++) {
        if(OutAlly[i].hp <= 0) OutAlly[i].hp = 0, OutAlly[i].bd = 1; 
        if(OutAlly[i].bd == 0) OutAlly[i].bX  += OutAlly[i].ms;
    }
    for(int i=0 ; i<OutEnemyCnt ; i++) {
        if(OutEnemy[i].hp <= 0) OutEnemy[i].hp = 0, OutEnemy[i].bd = 1;
        if(OutEnemy[i].bd == 0) OutEnemy[i].bX += OutEnemy[i].ms;
    }

    // Make Enemy
    if(fcnt % 30 == 0) {
        for(int i=0 ; i<Enemy.characterNum ; i++) {
            if(RR(Enemy.characters[i].ratio)) {
                OutEnemy[OutEnemyCnt] = Enemy.characters[i];
                OutEnemy[OutEnemyCnt].bX = 1700; // Enemy Castle Entrence
                OutEnemy[OutEnemyCnt].bd = 0;
                OutEnemyCnt++;
                break;
            }
        }
    }

    //attack
    for(int i=0 ; i<OutAllyCnt ; i++) {
        for(int j=0 ; j<OutEnemyCnt ; j++) {
            if(OutAlly[i].bX + 100 >= OutEnemy[j].bX) { // collided
                OutAlly[i].hp -=  (OutEnemy[j].dg - OutAlly[i].df);
                OutEnemy[j].hp -= (OutAlly[i].dg  - OutEnemy[j].df);
            }
        }
    }
}

void BattleKeyin() {

    // Move Battle Background
    if(GMX() <= 100 && ScreenX >= 3) ScreenX -= (100-GMX());
    else if(GMX() >= 540 && ScreenX < 2109 - 800) ScreenX += (GMX()-540); 
    if(ScreenX < 0) ScreenX = 0;
    else if(ScreenX > 2109 - 800) ScreenX = 2109 - 800;

    // icon click
    for(int i=0 ; i<Ally.characterNum ; i++) {
        if( MIA(640-(100+10)*(i+1), 10, 80, 80) && kp(VK_LBUTTON) && Cost-Ally.characters[i].cost > 0 ) {
            OutAlly[OutAllyCnt]     = Ally.characters[i];
            OutAlly[OutAllyCnt].bX  = 400; // Ally castle Entrence
            OutAlly[OutAllyCnt].bd  = 0;
            OutAllyCnt++;
        }
    }
}

void BattleRender() {
    
    // Render Background

    PO(0, 0, ScreenX, 0, 800, 450, BattleBackgroundDC);

    // Render icons

    for(int i=0 ; i<Ally.characterNum ; i++) {
        PT(800-(10+60)*(i+1), 10, 60, 60, Ally.characters[i].BattleIconDC);
    }

    // Render Allys

    for(int i=0 ; i<OutAllyCnt ; i++) {
        if(OutAlly[i].bd == 0 && OutAlly[i].bX+100 > ScreenX && OutAlly[i].bX < ScreenX + 800) {
            if(fcnt % 3 == 0) OutAlly[i].WalkSpriteCnt++;
            PT(OutAlly[i].bX-ScreenX, 340, 100, 100, OutAlly[i].WalkSpriteDC[OutAlly[i].WalkSpriteCnt%OutAlly[i].WalkSpriteNum]);
        }
    }

    // Render Enemy

    for(int i=0 ; i<OutEnemyCnt ; i++) {
        if(OutEnemy[i].bd == 0 && OutEnemy[i].bX+100 > ScreenX && OutEnemy[i].bX < ScreenX + 800) {
            if(fcnt % 3 == 0) OutEnemy[i].WalkSpriteCnt++;
            PT(OutEnemy[i].bX-ScreenX, 340, 100, 100, OutEnemy[i].WalkSpriteDC[OutEnemy[i].WalkSpriteCnt%OutEnemy[i].WalkSpriteNum]);
        }
    }

    // Render Arrows
    
    if(GMX() <= 100 && ScreenX >= 3)         PI(10, 215, 20, 20, ArrowLeftDC);
    if(GMX() >= 540 && ScreenX < 2109 - 800) PI(780, 215, 20, 20, ArrowLeftDC);
    // printf("render out\n");
}