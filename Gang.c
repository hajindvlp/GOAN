#include "Gang.h"

void GangUpgrade(int characterCode, int hpUp, int dgUp) {
    if(PlayerExp > 0) {
        PlayerExp--;
        gang.characters[characterCode].hp += hpUp;
        gang.characters[characterCode].dg += dgUp;
    }
}