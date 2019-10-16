#include "Main.h"

int main() {
    MainGame();
}

void MainGame() {
    MainInit();
    while(1) {
        MainUpdate();
        MainKeyin();
        MainRender();
    }
}

void MainInit() {
    MapSelect();
}

void MainUpdate() {

}

void MainKeyin() {

}

void MainRender() {

}