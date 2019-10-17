#include "Main.h"

int main() {
    printf("[*] Main Function\n");
    MainGame();
}

void MainGame() {
    printf("[*] MainGame Function\n");
    MainInit();
    while(1) {
        MainUpdate();
        MainKeyin();
        MainRender();
    }
}

void MainInit() {
    printf("[*] MainInit Function\n");
    Load();
    MapSelect();
}

void MainUpdate() {

}

void MainKeyin() {

}

void MainRender() {

}