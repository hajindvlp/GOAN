#include "Battle.h"

int BattleMain(int EnemyCode) {
    int key;
    system("mode 100, 38");

    ECode = EnemyCode;
    SetConsoleTitle("Battle");
    BattleInit();
    while(1) {
        fcnt++;
        key = BattleUpdate();
        if(key != 0) {
            if(key == -1) return 1;
            else if(key == 1) return 0;
        }
        BattleKeyin();
        BattleRender();
        Sleep(1000/FPS);
    }
}

void BattleInit() {

    ScreenX = 0;
    system("mode 100, 38");

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
        if(Cost >= Ally.characters[i].cost && fcnt % Ally.characters[i].sc == 0 && MIA(640-(8+48)*(i+1), 8, 48, 48) && kp(VK_LBUTTON) && Cost-Ally.characters[i].cost > 0 ) {
            OutAlly[OutAllyCnt]     = Ally.characters[i];
            OutAlly[OutAllyCnt].bX  = 175; // Ally castle Entrence
            OutAlly[OutAllyCnt].bd  = 0;
            Cost -= Ally.characters[i].cost;
            OutAllyCnt++;
        }
    }
}

int BattleUpdate() {

    // refresh frame cound to avoid integer overflow
    fcnt = fcnt%1110;

    // check Lose Win
    if(AllyCastle.hp <= 0) {
        return RenderLose();
    } else if(EnemyCastle.hp <= 0) {
        return RenderWin();
    }

    // coin movement update
    for(int i=0 ; i<coinNum ; i++) {
        if(coin[i].isRender && !(coin[i].x == COIN_X && coin[i].y == COIN_Y) && coin[i].fcnt != 30) {
            coin[i].x += (ScreenX+COIN_X-coin[i].x)/(30-coin[i].fcnt);
            coin[i].y += coin[i].vy;
            coin[i].fcnt++;
        } else if(coin[i].isRender) {
            Cost++;
            coin[i].isRender = 0;
        }
    }

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

        if(!isCollided && OutAlly[i].bX + OutAlly[i].Width - 30 >= 1960) {
            if(fcnt % OutAlly[i].as == 0) {
                EnemyCastle.hp -= OutAlly[i].dg;
            }
            OutAlly[i].bw = 0;
            OutAlly[i].ba = 1;
            isCollided = 1;
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
            coin[coinNum].x = OutEnemy[i].bX;   // Add vx, vy for animation
            coin[coinNum].y = GROUND-40;
            coin[coinNum].vy = (COIN_Y - coin[coinNum].y)/30;
            coin[coinNum].isRender = 1;
            coin[coinNum].fcnt = 0;
            coinNum++;
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

        if(!isCollided && OutEnemy[i].bX - OutEnemy[i].Width + 30 <= 175) {
            if(fcnt % OutEnemy[i].as == 0) {
                AllyCastle.hp -= OutEnemy[i].dg;
            }
            OutEnemy[i].bw = 0;
            OutEnemy[i].ba = 1;
            isCollided = 1;
        }

        if(!isCollided && OutEnemy[i].bd == 0) OutEnemy[i].bX += OutEnemy[i].ms;
    }

    // Make Enemy
    if(fcnt % 30 == 0) {
        for(int i=0 ; i<Enemy.characterNum ; i++) {
            if(RR(Enemy.characters[i].ratio)) {
                OutEnemy[OutEnemyCnt] = Enemy.characters[i];
                OutEnemy[OutEnemyCnt].bX = 1960-Enemy.characters[i].Width; // Enemy Castle Entrence
                OutEnemy[OutEnemyCnt].bd = 0;
                OutEnemyCnt++;
                break;
            }
        }
    }

    return 0;
}

void BattleRender() {

    // Render Background

    PO(0, 0, ScreenX, 0, SCREEN_WIDTH, 600, BattleBackgroundDC[ECode-1]);

    // Render icons

    for(int i=Ally.characterNum-1 ; i>=0 ; i--) {
        PT(SCREEN_WIDTH-(10+60)*(i+1), 10, 60, 60, Ally.characters[i].BattleIconDC);
    }

    // Render Enemy

    for(int i=0 ; i<OutEnemyCnt ; i++) {
        if(OutEnemy[i].bd == 0 && OutEnemy[i].bX+OutEnemy[i].Width > ScreenX && OutEnemy[i].bX < ScreenX + SCREEN_WIDTH) {
            if(OutEnemy[i].bw) {
                if(fcnt % 3 == 0) OutEnemy[i].WalkSpriteCnt++, OutEnemy[i].WalkSpriteCnt%=OutEnemy[i].WalkSpriteNum;
                PT(OutEnemy[i].bX-ScreenX, GROUND - OutEnemy[i].Height, OutEnemy[i].Width, OutEnemy[i].Height,
                   OutEnemy[i].WalkSpriteDC[OutEnemy[i].WalkSpriteCnt]);
            } else if(OutEnemy[i].ba) {
                if(fcnt % 3 == 0) OutEnemy[i].AttackSpriteCnt++, OutEnemy[i].AttackSpriteCnt%=OutEnemy[i].AttackSpriteNum;
                PT(OutEnemy[i].bX-ScreenX, GROUND - OutEnemy[i].Height, OutEnemy[i].Width, OutEnemy[i].Height,
                   OutEnemy[i].AttackSpriteDC[OutEnemy[i].AttackSpriteCnt]);
            }
        }
        else if(OutEnemy[i].bd == 1 && OutEnemy[i].DieSpriteCnt < OutEnemy[i].DieSpriteNum) {
            if(fcnt % 3 == 0) OutEnemy[i].DieSpriteCnt++;
            PT(OutEnemy[i].bX-ScreenX, GROUND - OutEnemy[i].Height, OutEnemy[i].Width, OutEnemy[i].Height,
               OutEnemy[i].DieSpriteDC[OutEnemy[i].DieSpriteCnt]);
        }
    }

    // Render Allys

    for(int i=0 ; i<OutAllyCnt ; i++) {
        if(OutAlly[i].bd == 0 && OutAlly[i].bX+OutEnemy[i].Width > ScreenX && OutAlly[i].bX < ScreenX + 800) {
            if(OutAlly[i].bw) {   
                if(fcnt % 3 == 0) OutAlly[i].WalkSpriteCnt++, OutAlly[i].WalkSpriteCnt%=OutAlly[i].WalkSpriteNum;
                PT(OutAlly[i].bX-ScreenX, GROUND - OutAlly[i].Height, OutAlly[i].Width, OutAlly[i].Height, 
                   OutAlly[i].WalkSpriteDC[OutAlly[i].WalkSpriteCnt]);
            } else if(OutAlly[i].ba) {
                if(fcnt % 3 == 0) OutAlly[i].AttackSpriteCnt++, OutAlly[i].AttackSpriteCnt%=OutAlly[i].AttackSpriteNum;
                PT(OutAlly[i].bX-ScreenX, GROUND - OutAlly[i].Height, OutAlly[i].Width, OutAlly[i].Height,
                   OutAlly[i].AttackSpriteDC[OutAlly[i].AttackSpriteCnt]);
            } 
        }
        else if(OutAlly[i].bd == 1 && OutAlly[i].DieSpriteCnt < OutAlly[i].DieSpriteNum) {
            if(fcnt % 3 == 0) OutAlly[i].DieSpriteCnt++;
            PT(OutAlly[i].bX-ScreenX, GROUND - OutAlly[i].Height, OutAlly[i].Width, OutAlly[i].Height,
               OutAlly[i].DieSpriteDC[OutAlly[i].DieSpriteCnt]);
        }
    }

    // Render Coin
    PT(COIN_X, COIN_Y, 40, 40, CoinDC);
    for(int i=0 ; i<coinNum ; i++) {
        if(coin[i].isRender) {
            PT(coin[i].x-ScreenX, coin[i].y, 40, 40, CoinDC);
        }
    }
    
    // Render Castle Health
    PT(10-ScreenX, 200, 320, 20, AllyHealthBar1DC);
    PT(10-ScreenX+(320*AllyCastle.hp)/AllyCastle.MaxHp, 200, (320*(AllyCastle.MaxHp-AllyCastle.hp))/AllyCastle.MaxHp, 20, AllyHealthBar2DC);
    PT(2109-ScreenX-330, 200, 320, 20, EnemyHealthBar1DC);
    PT(2109-ScreenX-330, 200, (320*(EnemyCastle.MaxHp-EnemyCastle.hp))/EnemyCastle.MaxHp, 20, EnemyHealthBar2DC);

    // PN(0, 0, 300, 50, GMX());
}

int RenderLose() {
    int BackTransparency = 0x7f;
    int tmp = 0, oldTmp = -1;
    
    BattleBackBldFunc.SourceConstantAlpha = BackTransparency;
    AlphaBlend(ConsoleDC, 0, 0, 800, 600, BlackDC, 0, 0, 800, 600, BattleBackBldFunc);

    while(1) {

        if(oldTmp != tmp) {
            PI(0, 75, 800, 450, LoseScreenDC);
            if     (tmp == 1) PT(0, 75, 800, 450, LoseMapDC);
            else if(tmp == 2) PT(0, 75, 800, 450, LoseStoreDC);
            else if(tmp == 3) PT(0, 75, 800, 450, LoseRetryDC);
            oldTmp = tmp;
        }

        if (MIA(210, 240, 117, 26)) {
            tmp = 1;
            if(kp(VK_LBUTTON)) return 1;
        } else if (MIA(340, 240, 117, 26)) {
            tmp = 2;
            if(kp(VK_LBUTTON)) return -1;
        } else if (MIA(252, 288, 157, 60)) {
            tmp = 3;
            if(kp(VK_LBUTTON)) return BattleMain(ECode);
        }
        else tmp = 0;
    }
}

int RenderWin() {
    int BackTransparency = 0x7f;
    int tmp = 0, oldTmp = -1;

    BattleBackBldFunc.SourceConstantAlpha = BackTransparency;
    AlphaBlend(ConsoleDC, 0, 0, 800, 600, BlackDC, 0, 0, 800, 600, BattleBackBldFunc);

    Conquered[ECode-1] = 1;
    PlayerFile = fopen("./resources/Files/PLAYER", "w+");
    for(int i=0 ; i<5 ; i++) fprintf(PlayerFile, "%d ", Conquered[i]);

    while(1) {
        if(oldTmp != tmp) {
            PI(0, 75, 800, 450, WinScreenDC);
            if     (tmp == 1) PT(0, 75, 800, 450, WinMapDC);
            else if(tmp == 2) PT(0, 75, 800, 450, WinStoreDC);
            oldTmp = tmp;
        }

        if (MIA(210, 325, 150, 35)) {
            tmp = 1;
            if(kp(VK_LBUTTON)) return -1;
        } else if (MIA(340, 325, 150, 35)) {
            tmp = 2;
            if(kp(VK_LBUTTON)) return 1;
        } 
        else tmp = 0;
        
    }
}