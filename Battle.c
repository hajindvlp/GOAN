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
    coinNum = 0;

    Ally = gang;
    EnemyLoad(ECode);
}

void BattleKeyin() {

    // Move Battle Background
    if(GMX() <= 100 && ScreenX >= 3) ScreenX -= (100-GMX());
    else if(GMX() >= 540 && ScreenX < 2109 - 800) ScreenX += (GMX()-540); 
    if(ScreenX < 0) ScreenX = 0;
    else if(ScreenX > 2109 - 800) ScreenX = 2109 - 800;

    // icon click
    for(int i=0 ; i<Ally.characterNum ; i++) {
        if(fcnt % Ally.characters[i].sc == 0 && MIA(640-(100+10)*(i+1), 10, 80, 80) && kp(VK_LBUTTON) && Cost-Ally.characters[i].cost > 0 ) {
            OutAlly[OutAllyCnt]     = Ally.characters[i];
            OutAlly[OutAllyCnt].bX  = 175; // Ally castle Entrence
            OutAlly[OutAllyCnt].bd  = 0;
            OutAllyCnt++;
        }
    }
}

void BattleUpdate() {

    // refresh frame cound to avoid integer overflow
    fcnt = fcnt%1110;

    // move & check Die & attack
    for(int i=0 ; i<OutAllyCnt  ; i++) {  // Ally's perspective

        OutAlly[i].bw = 1; // Ally is Walking by default

        int isCollided = 0;
        
        if(OutAlly[i].bd == 0 && (OutAlly[i].hp < 0 || OutAlly[i].bX > 2109) ) { // check death
            OutAlly[i].hp = 0;
            OutAlly[i].bd = 1; 
            OutAlly[i].ba = 0;
            OutAlly[i].bw = 0;
            OutAlly[i].DieSpriteCnt = 0;
        }

        for(int j=0 ; j<OutEnemyCnt ; j++) { // Ally -> Enemy
            if(OutAlly[i].bd == 0 && OutEnemy[j].bd == 0 && OutAlly[i].bX + OutAlly[i].Width - 30 >= OutEnemy[j].bX) { // collided
                if(fcnt % OutAlly[i].as == 0) {
                    OutEnemy[j].hp -= (OutAlly[i].dg - OutEnemy[j].df); // attack if attack speed is on time
                } 
                OutAlly[i].bw = 0;
                OutAlly[i].ba = 1;
                isCollided = 1;
                break;
            }
        }

        if(!isCollided && OutAlly[i].bd == 0) OutAlly[i].bX  += OutAlly[i].ms;
    }

    for(int i=0 ; i<OutEnemyCnt ; i++) { // Enemy's perspective

        OutEnemy[i].bw = 1; // Ally is Walking by default

        int isCollided = 0;
        
        if(OutEnemy[i].bd == 0 && (OutEnemy[i].hp <= 0 || OutEnemy[i].bX < 0)) { // death check
            // Make Enemy Die
            OutEnemy[i].hp = 0;
            OutEnemy[i].bd = 1; 
            OutEnemy[i].bw = 0;
            OutEnemy[i].ba = 0;
            OutEnemy[i].DieSpriteCnt = 0;

            // Set Coin
            // coin[coinNum].x = OutEnemy[i].bX;   // Add vx, vy for animation
            // coinNum++;
        } 

        for(int j=0 ; j<OutAllyCnt ; j++) { // Enemy -> Ally
            if(OutEnemy[i].bd == 0 && OutAlly[j].bd == 0 && OutEnemy[i].bX - OutEnemy[i].Width + 30 <= OutAlly[j].bX) {
                if(fcnt % OutEnemy[i].as == 0) {
                    OutAlly[j].hp -= (OutEnemy[i].dg - OutAlly[j].df);
                } 
                OutEnemy[i].bw = 0;
                OutEnemy[i].ba = 1;
                isCollided = 1;
                break;
            }
        }

        if(!isCollided && OutEnemy[i].bd == 0) OutEnemy[i].bX += OutEnemy[i].ms;
    }

    // Make Enemy
    if(fcnt % 30 == 0) {
        for(int i=0 ; i<Enemy.characterNum ; i++) {
            if(RR(Enemy.characters[i].ratio)) {
                OutEnemy[OutEnemyCnt] = Enemy.characters[i];
                OutEnemy[OutEnemyCnt].bX = 1960; // Enemy Castle Entrence
                OutEnemy[OutEnemyCnt].bd = 0;
                OutEnemyCnt++;
                break;
            }
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

    // Render Enemy

    for(int i=0 ; i<OutEnemyCnt ; i++) {
        if(OutEnemy[i].bd == 0 && OutEnemy[i].bX+100 > ScreenX && OutEnemy[i].bX < ScreenX + 800) {
            if(OutEnemy[i].bw) {
                if(fcnt % 3 == 0) OutEnemy[i].WalkSpriteCnt++, OutEnemy[i].WalkSpriteCnt%=OutEnemy[i].WalkSpriteNum;
                PT(OutEnemy[i].bX-ScreenX, 440 - OutEnemy[i].Height, OutEnemy[i].Width, OutEnemy[i].Height,
                   OutEnemy[i].WalkSpriteDC[OutEnemy[i].WalkSpriteCnt]);
            } else if(OutEnemy[i].ba) {
                if(fcnt % 3 == 0) OutEnemy[i].AttackSpriteCnt++, OutEnemy[i].AttackSpriteCnt%=OutEnemy[i].AttackSpriteNum;
                PT(OutEnemy[i].bX-ScreenX, 440 - OutEnemy[i].Height, OutEnemy[i].Width, OutEnemy[i].Height,
                   OutEnemy[i].AttackSpriteDC[OutEnemy[i].AttackSpriteCnt]);
            }
        }
        else if(OutEnemy[i].DieSpriteCnt < OutEnemy[i].DieSpriteNum && OutEnemy[i].bd) {
            if(fcnt % 3 == 0) OutEnemy[i].DieSpriteCnt++, OutEnemy[i].DieSpriteCnt%=OutEnemy[i].DieSpriteNum;
            PT(OutEnemy[i].bX-ScreenX, 440 - OutEnemy[i].Height, OutEnemy[i].Width, OutEnemy[i].Height,
               OutEnemy[i].DieSpriteDC[OutEnemy[i].DieSpriteCnt]);
        }
    }

    // Render Allys

    for(int i=0 ; i<OutAllyCnt ; i++) {
        if(OutAlly[i].bd == 0 && OutAlly[i].bX+100 > ScreenX && OutAlly[i].bX < ScreenX + 800) {
            if(OutAlly[i].bw) {   
                if(fcnt % 3 == 0) OutAlly[i].WalkSpriteCnt++, OutAlly[i].WalkSpriteCnt%=OutAlly[i].WalkSpriteNum;
                PT(OutAlly[i].bX-ScreenX, 440 - OutAlly[i].Height, OutAlly[i].Width, OutAlly[i].Height, 
                   OutAlly[i].WalkSpriteDC[OutAlly[i].WalkSpriteCnt]);
            } else if(OutAlly[i].ba) {
                if(fcnt % 3 == 0) OutAlly[i].AttackSpriteCnt++, OutAlly[i].AttackSpriteCnt%=OutAlly[i].AttackSpriteNum;
                PT(OutAlly[i].bX-ScreenX, 440 - OutAlly[i].Height, OutAlly[i].Width, OutAlly[i].Height,
                   OutAlly[i].AttackSpriteDC[OutAlly[i].AttackSpriteCnt]);
            } 
        }
        else if(OutAlly[i].DieSpriteCnt < OutAlly[i].DieSpriteNum && OutAlly[i].bd) {
            if(fcnt % 3 == 0) OutAlly[i].DieSpriteCnt++, OutAlly[i].DieSpriteCnt%=OutAlly[i].DieSpriteNum;
            PT(OutAlly[i].bX-ScreenX, 440 - OutAlly[i].Height, OutAlly[i].Width, OutAlly[i].Height,
               OutAlly[i].DieSpriteDC[OutAlly[i].DieSpriteCnt]);
        }
    }

    // Render Coin

    for(int i=0 ; i<coinNum ; i++) {
        if(coin[i].x+40 > ScreenX) {
            PT(coin[i].x-ScreenX, 400, 40, 40, CoinDC);
        }
    }

    // Render Arrows
    
    // if(GMX() <= 100 && ScreenX >= 3)         PI(10, 215, 20, 20, ArrowLeftDC);
    // if(GMX() >= 540 && ScreenX < 2109 - 800) PI(780, 215, 20, 20, ArrowLeftDC);
    // printf("render out\n");
}