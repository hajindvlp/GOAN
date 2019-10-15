#include "Gang.h"

void GangUpgrade(int characterCode, int hpUp, int dgUp) {
    if(exp > 0) {
        exp--;
        gang.characters[characterCode].hp += hpUp;
        gang.characters[characterCode].dg += dgUp;
    }
}