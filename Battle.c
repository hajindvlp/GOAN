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
    fcnt = 0;
    Cost = 100;
}

void BattleUpdate() {

    // move characters
    for(int i=0 ; i<OutAllyCnt  ; i++) OutAlly[i].bX  += OutAlly[i].ms;
    for(int i=0 ; i<OutEnemyCnt ; i++) OutEnemy[i].bX += OutEnemy[i].ms;

    // Make Enemy

    //collision check Ally<->Enemy / Ally<->EnemyCastle / Enemy<->AllyCastle

    //attack
    
    //Sumon Enemy randomly
}

void BattleKeyin() {

    // screen movement

    // Move Battle Background
    if(GMX() <= 100 && ScreenX >= 3) ScreenX -= (100-GMX());
    else if(GMX() >= 540 && ScreenX < 2109 - 800) ScreenX += (GMX()-540); 
    if(ScreenX < 0) ScreenX = 0;
    else if(ScreenX > 2109 - 800) ScreenX = 2109 - 800;

    // icon click
    for(int i=0 ; i<gang.characterNum ; i++) {
        if( MIA(640-(100+10)*(i+1), 10, 80, 80) && kp(VK_LBUTTON) && Cost-gang.characters[i].cost > 0 ) {
            printf("Clicked %d\n", i);
            OutAlly[OutAllyCnt]     = gang.characters[i];
            OutAlly[OutAllyCnt].bX  = 400; // Ally castle Entrence
            OutAlly[OutAllyCnt].bd  = 0;
            OutAllyCnt++;
        }
    }

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

    PO(0, 0, ScreenX, 0, 800, 450, BattleBackgroundDC);

    // Render icons

    for(int i=0 ; i<gang.characterNum ; i++) {
        PT(800-(10+60)*(i+1), 10, 60, 60, gang.characters[i].BattleIconDC);
    }

    // Render Allys

    for(int i=0 ; i<OutAllyCnt ; i++) {
        if(OutAlly[i].bX+100 > ScreenX) {
            if(fcnt % 3 == 0) OutAlly[i].WalkSpriteCnt++;
            PT(OutAlly[i].bX-ScreenX, 340, 100, 100, OutAlly[i].WalkSpriteDC[OutAlly[i].WalkSpriteCnt%OutAlly[i].WalkSpriteNum]);
        }
    }

    // Render Enemy

    // Render Arrows
    
    if(GMX() <= 100 && ScreenX >= 3)         PI(10, 215, 20, 20, ArrowLeftDC);
    if(GMX() >= 540 && ScreenX < 2109 - 800) PI(780, 215, 20, 20, ArrowLeftDC);

}