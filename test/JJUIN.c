#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h> ///_kbhit() , _getch()
#include <mmsystem.h>
#include <time.h>

#define WIDTH 130
#define HEIGHT 40

typedef struct ITEM
{
    char *name;
    int number;
} item;

typedef struct INFO
{
    char *name;   /// 이름
    char *gender; /// 성별
    char *where;  /// 반
    int grade;       /// 학년 (초기설정 1학년)
    int money;         ///돈
    int house; ///귀가권
    int level; ///레벨
    int tbrief ; /// 선생님 신뢰도
    int happy; /// 행복도
    char *title; /// 타이틀
    int friend; ///친구수
    char *group; //동아리
    int helptime;

    item i[10];
} strinfo;


strinfo player;
item it[15];

int xmouse;
int ymouse;

time_t timer; ///시간 저장


    HANDLE COUT = 0;    // 콘솔 출력 장치
    HANDLE CIN = 0;        // 콘솔 입력 장치
    DWORD mode;
    WORD key;
    COORD pos;

int main()
{

    resizeConsole(WIDTH,HEIGHT);
    /**
    TEST설정
    */
    player.name = "JJUIN";
    player.gender = "Man";
    player.level = 1;
    player.title = "ADMIN";
    player.tbrief  = 100;
    player.money = 10000;


    all_print();
    menuplay();
    while(1)
        dimigoin();
    /*
    timer = time(NULL); //시간 로드 함수
    */


}

void firstset() ///처음 환경설정
{
    gotoxy(31,8);
    printf("                Welcome to The Dimi School");
    gotoxy(31,10);
    printf("이 게임은 A Dark Room 에서 영감을 받아 디미고 버전으로 제작하였습니다.");
    gotoxy(31,12);
    printf("                    Product By JJUIN");

    Sleep(3000); ///TEST version , 후에 추가, 제거 , 수정 요망
    system("cls");

    gotoxy(31,8);
    printf("닉네임을 입력해 주시기 바랍니다.\n");
    scanf("%s",player.name);

    system("cls");
    gotoxy(31,8);
    printf("닉네임, %s로 설정합니다.",player.name);
    Sleep(1000);

    system("cls");
    gotoxy(31,8);
    printf("성별을 선택하여 주시기 바랍니다.");
    gotoxy(25,10);
    printf("┌─────────────────────┐\n"); ///25,10 - 47,12
    gotoxy(25,11);
    printf("│        BOY          │\n");
    gotoxy(25,12);
    printf("└─────────────────────┘\n");
    gotoxy(50,10);
    printf("┌─────────────────────┐\n"); ///50,10 - 72,12
    gotoxy(50,11);
    printf("│        GIRL         │\n");
    gotoxy(50,12);
    printf("└─────────────────────┘\n");

    checkmouse();
    if(xmouse>=25 && xmouse <= 47){
        if(ymouse >=10 && ymouse <= 12){
            player.gender = "man";
            system("cls");
            gotoxy(31,8);
            printf("성별이 남자로 결정되었습니다.\n");
        }
    }
    if(xmouse>=50 && xmouse <= 72){
        if(ymouse >=10 && ymouse <= 12){
            player.gender = "Girl";
            system("cls");
            gotoxy(31,8);
            printf("성별이 여자로 결정되었습니다.\n");
        }
    }

    Sleep(1000);
    system("cls");
    gotoxy(31,8);
    printf("학과를 설정해주세요\n");
    gotoxy(0,10);
    printf("┌─────────────────────┐\n"); ///0,10 - 22,12
    gotoxy(0,11);
    printf("│        이비과       │\n");
    gotoxy(0,12);
    printf("└─────────────────────┘\n");
    gotoxy(25,10);
    printf("┌─────────────────────┐\n"); ///25,10 - 48,12
    gotoxy(25,11);
    printf("│        디컨과       │\n");
    gotoxy(25,12);
    printf("└─────────────────────┘\n");
    gotoxy(50,10);
    printf("┌─────────────────────┐\n"); ///50,10 - 73,12
    gotoxy(50,11);
    printf("│        웹플과       │\n");
    gotoxy(50,12);
    printf("└─────────────────────┘\n");
    gotoxy(75,10);
    printf("┌─────────────────────┐\n"); ///75,10 - 100,12
    gotoxy(75,11);
    printf("│        해방과       │\n");
    gotoxy(75,12);
    printf("└─────────────────────┘\n");

    checkmouse();
    if(xmouse>=0 && xmouse <= 22){
        if(ymouse >=10 && ymouse <= 12){
            player.where = "이비과";
            system("cls");
            gotoxy(31,8);
            printf("학과가 이비로 결정되었습니다.\n");
        }
    }

    if(xmouse>=25 && xmouse <= 48){
        if(ymouse >=10 && ymouse <= 12){
            player.where = "디컨과";
            system("cls");
            gotoxy(31,8);
            printf("학과가 디컨으로 결정되었습니다.\n");
        }
    }if(xmouse>=50 && xmouse <= 73){
        if(ymouse >=10 && ymouse <= 12){
            player.where = "웹플과";
            system("cls");
            gotoxy(31,8);
            printf("학과가 웹플로 결정되었습니다.\n");
        }
    }if(xmouse>=75 && xmouse <= 100){
        if(ymouse >=10 && ymouse <= 12){
            player.where = "해방과";
            system("cls");
            gotoxy(31,8);
            printf("학과가 해방으로 결정되었습니다.\n");
        }
    }



    system("cls");
    printf("┌────────────────────────────┐\n");
    printf("│                            │\n");
    printf("│          YOUT INFO         │\n");
    printf("│                            │\n");
    printf("│ Name : %s                   \n",player.name);
    printf("│ Gender : %s              \n",player.gender);
    printf("│ grade : %d                  │\n",player.grade);
    printf("│ Class : %s             │\n",player.where);
    printf("│                            │\n");
    printf("│                            │\n");
    printf("│ Money : %d                  │\n",player.money);
    printf("│                            │\n");
    printf("│                            │\n");
    printf("└────────────────────────────┘\n");

    Sleep(3000);
    system("cls");
    gotoxy(31,8);
    printf("당신의 정보가 맞습니까?\n");
    gotoxy(25,10);
    printf("┌─────────────────────┐\n"); ///25,10 - 48,12
    gotoxy(25,11);
    printf("│          YES        │\n");
    gotoxy(25,12);
    printf("└─────────────────────┘\n");
    gotoxy(50,10);
    printf("┌─────────────────────┐\n"); ///50,10 - 73,12
    gotoxy(50,11);
    printf("│          NO         │\n");
    gotoxy(50,12);
    printf("└─────────────────────┘\n");
    checkmouse();
    if(xmouse>=25 && xmouse <= 48){
        if(ymouse >=10 && ymouse <= 12){
            tutorial();
        }
    }if(xmouse>=50 && xmouse <= 73){
        if(ymouse >=10 && ymouse <= 12){
            system("cls");
            gotoxy(31,8);
            printf("다시 설정을 시작하겠습니다.\n");
            Sleep(1000);
            firstset();
        }

    }
}

/**LEVEL SETTING**/

void tutorial() ///튜토리얼
{
     system("cls");
            gotoxy(31,8);
            printf("    Game Start . . .\n");
            Sleep(500);
            gotoxy(31,10);
            printf("자동저장을 시작합니다 . . .");

            system("cls");
            gotoxy(5,2);
            printf("컴퓨터를 키고 그 사이트에 들어가니 노랫소리가 들려온다 . . .\n");
            //firstmusic(); //디미고 교가 나올 예정, 미개발
            Sleep(1000);
            gotoxy(31,4);
            printf("\"입학을 축하합니다!\"");
            Sleep(1000);
            gotoxy(31,6);
            printf("\"당신은 이제 한국디지털미디어고등학교에 입학하셨습니다.\"");
            Sleep(1000);
            gotoxy(31,8);
            printf("\"약 두달 뒤 입학 전 시험이 있을 예정입니다.\"\n(이 시험을 통해 당신의 초반 능력치가 결정됩니다)");
            Sleep(2000);
    system("cls");
    gotoxy(31,8);
    printf("            두달 후,, ");
    Sleep(1000);
    gotoxy(31,10);
    printf("그럼 지금부터 시험을 시작하도록 하겠습니다.");
    Sleep(1000);
    system("cls");
    gotoxy(31,8);
    printf("┌───────────────────────────────────────┐\n");
    gotoxy(31,9);
    printf("│                                       │\n");
    gotoxy(31,10);
    printf("│                1번 문제               │\n");
    gotoxy(31,11);
    printf("┝───────────────────────────────────────┫\n");
    gotoxy(31,12);
    printf("│    디미고가 위치한 곳은 어디일까요?   │\n");
    gotoxy(31,13);
    printf("│                                       │\n");
    gotoxy(31,14);
    printf("│                                       │\n");
    gotoxy(31,15);
    printf("│                                       │\n");
    gotoxy(31,16);
    printf("└───────────────────────────────────────┘\n"); //31,16
    gotoxy(31,18);
    printf("┌─────────────────────┐\n");
    gotoxy(31,19);
    printf("│         안산        │\n");
    gotoxy(31,20);
    printf("└─────────────────────┘\n");
    gotoxy(56,18);
    printf("┌─────────────────────┐\n");
    gotoxy(56,19);
    printf("│        인천         │\n");
    gotoxy(56,20);
    printf("└─────────────────────┘\n");

    checkmouse();
    if(xmouse>=31 && xmouse <= 54){
        if(ymouse >=18 && ymouse <= 20){
            system("cls");
            gotoxy(35,8);
            printf("정답입니다!");
            gotoxy(31,10);
            printf("1000원이 지급되었습니다.");
            gotoxy(31,12);
            printf("선생님의 신뢰도가 1 상승했습니다.");
            player.tbrief  += 1;
            player.money += 1000;
            Sleep(2000);
        }
    }if(xmouse>=56 && xmouse <= 79){
        if(ymouse >=18 && ymouse <= 20){
          system("cls");
            gotoxy(35,8);
            printf("오답입니다.");
            gotoxy(31,10);
            printf("선생님의 신뢰도가 1 떨어졌습니다.");
            player.tbrief  -= 1;
            Sleep(2000);
        }

    }

    system("cls");
    gotoxy(31,8);
    printf("┌───────────────────────────────────────┐\n");
    gotoxy(31,9);
    printf("│                                       │\n");
    gotoxy(31,10);
    printf("│                2번 문제               │\n");
    gotoxy(31,11);
    printf("┝───────────────────────────────────────┫\n");
    gotoxy(31,12);
    printf("│  디미고의 1학년 프로그래밍을          │\n");
    gotoxy(31,13);
    printf("│                                       │\n");
    gotoxy(31,14);
    printf("│  가르치시는 선생님의 성함은?          │\n");
    gotoxy(31,15);
    printf("│                                       │\n");
    gotoxy(31,16);
    printf("└───────────────────────────────────────┘\n"); //31,17


    char answer[20],correct[20] = "함지현선생님";
    printf("\n답안을 입력하여 주시기 바랍니다. (ㅇㅇㅇ선생님 으로 입력해주세요!) : ");
    scanf("%s",answer);
    if(strcmp(answer,correct) == 0){
            system("cls");
            gotoxy(35,8);
            printf("정답입니다!");
            gotoxy(31,10);
            printf("2000원이 지급되었습니다.");
            gotoxy(31,12);
            printf("선생님의 신뢰도가 2 상승했습니다.");
            player.tbrief  += 2;
            player.money += 2000;
            Sleep(2000);
    }
    else {
         system("cls");
            gotoxy(35,8);
            printf("오답입니다.");
            gotoxy(31,10);
            printf("선생님의 신뢰도가 1 떨어졌습니다.");
            player.tbrief  -= 1;
            Sleep(2000);
    }

    system("cls");
    gotoxy(31,8);
    printf("┌───────────────────────────────────────┐\n");
    gotoxy(31,9);
    printf("│                                       │\n");
    gotoxy(31,10);
    printf("│                3번 문제               │\n");
    gotoxy(31,11);
    printf("┝───────────────────────────────────────┫\n");
    gotoxy(31,12);
    printf("│  개발자의 닉네임은 무엇일까요?        │\n");
    gotoxy(31,13);
    printf("│                                       │\n");
    gotoxy(31,14);
    printf("│  Hint : 게임 처음 화면                │\n");
    gotoxy(31,15);
    printf("│                                       │\n");
    gotoxy(31,16);
    printf("└───────────────────────────────────────┘\n"); //31,17

    gotoxy(31,18);
    printf("┌─────────────────────┐\n");
    gotoxy(31,19);
    printf("│        JJUIN        │\n");
    gotoxy(31,20);
    printf("└─────────────────────┘\n");
    gotoxy(56,18);
    printf("┌─────────────────────┐\n");
    gotoxy(56,19);
    printf("│        HunSeol      │\n");
    gotoxy(56,20);
    printf("└─────────────────────┘\n");

    checkmouse();
    if(xmouse>=31 && xmouse <= 54){
        if(ymouse >=18 && ymouse <= 20){
            system("cls");
            gotoxy(35,8);
            printf("정답입니다!");
            gotoxy(31,10);
            printf("5000원이 지급되었습니다.");
            gotoxy(31,12);
            printf("히든 타이틀 「개발자의 사랑」 을 흭득하셨습니다.");
            player.title = "개발자의사랑";
            player.money += 5000;
            Sleep(2000);
        }
    }if(xmouse>=56 && xmouse <= 79){
        if(ymouse >=18 && ymouse <= 20){
          system("cls");
            gotoxy(35,8);
            printf("오답입니다.");
            gotoxy(31,10);
            printf("선생님의 신뢰도가 1 떨어졌습니다.");
            player.tbrief  -= 1;
            Sleep(2000);
        }

    }

    system("cls");
    gotoxy(31,8);
    printf("이상 시험을 종료하겠습니다. 수고하셨습니다.");
    Sleep(500);
    gotoxy(31,10);
    printf("집으로 돌아가던 중, 《정희범 선생님》 을 만났습니다.");
    Sleep(1000);
    gotoxy(31,12);
    printf("\"지금부터 입학 게임을 시작하겠습니다.\"");
    gotoxy(31,13);
    Sleep(500);
    printf("미니게임이 시작됩니다 . . .");
    Sleep(1000);
    //game_keepmiddle(); //가운데 맞추는 미니게임, 미개발;

    system("cls");
    gotoxy(31,8);
    printf("입학을 진심으로 축하합니다.");
    Sleep(1000);
    gotoxy(31,10);
    printf("시작하려면 아무키나 눌러주시기 바랍니다.");
    if(getch()){
        return;
    }
}

void classroom() ///교실
{
    classroom_printing();
    checkmouse();
    int classtime = 0, friendtime = 0;


        if(xmouse>=0 && xmouse <= 23 ){
            if(ymouse >=3 && ymouse <= 5){
                /*수업 트리거*/
                int m;
                srand(time(NULL));
                m = (rand()%100 +1) * 10;
                player.money += m;
                player.happy--;
                classtime = timer;
                gotoxy(0,15);
                printf("돈 %d원 흭득! %d %d",m,timer,classtime);
                times(1);
                gotoxy(0,15);
                printf("                         ");
                timer = time(NULL);

            }
        }

        if(xmouse>=0 && xmouse <= 23 ){
            if(ymouse >=7 && ymouse <= 9){
                /*친구 트리거*/
                srand(time(NULL));
                int f = (rand()%5 + 1);
                player.friend += f;
                player.happy -= 3;
                gotoxy(0,15);
                printf("친구 %d명을 사귀었습니다!",f);
                times(1);
                gotoxy(0,15);
                printf("                         ");
            }
        }


}
void group() ///동아리
{
    group_printing();
    checkmouse();
    if(xmouse >=25 && xmouse <= 48 ){
        gotoxy(27,9);
        printf("                         ");
        player.money -= 20000; /// 동아리 가입비 2만원
        if(ymouse >=10 && ymouse <= 11){ //코베
            player.group = "codebackery";
            player.tbrief += 20;
        }
        if(ymouse >= 12 && ymouse <=13){ //Truct
            player.group = "trust";
        }
        if(ymouse >=14 && ymouse <= 15 ){ //스텔스
            player.group = "stelth";
        }
        if(ymouse >=16 && ymouse <= 17 ){ //스텔스
            player.group = "kuze";
        }
        if(ymouse >=18 && ymouse <=19){ //LUNA
            player.group = "luna";
        }
        if(ymouse >=20 && ymouse <=21){ //TED
            player.group = "jnj";
            player.helptime += 20;
        }
        if(ymouse >=22 && ymouse <=23){ //소프트윙
            player.group = "softwing";
        }
        if(ymouse >=24 && ymouse <=25){ //도담
            player.group = "dodam";
            player.tbrief += 20;
        }
        if(ymouse >=26 && ymouse <=27){ //Fregic
            player.group = "fregic";
        }
        if(ymouse >=28 && ymouse <=30){ //TTL
            player.group = "TTL";
        }
    }
}

void shop()
{

    shop_printing();
    checkmouse();
    if(xmouse >= 25 && xmouse <= 48){

        if(ymouse >= 6 && ymouse <= 7 ) {
            inputitem("음료수",700);
        }
        if(ymouse >= 8 && ymouse <= 9 ) {
            inputitem("아이스크림",500);
        }
        if(ymouse >= 10 && ymouse <= 11 ) {
            inputitem("핫바",1300);
        }
        if(ymouse >= 12 && ymouse <= 13 ) {
            inputitem("찰떡피자",1500);
        }
        if(ymouse >= 14 && ymouse <= 15 ) {
            inputitem("팬류",500);
        }
        if(ymouse >= 16 && ymouse <= 17 ) {
            inputitem("공책",500);
        }
        if(ymouse >= 18 && ymouse <= 19 ) {
            inputitem("지우개",500);
        }
        if(ymouse >= 20 && ymouse <= 21 ) {
            inputitem("교과서",5000);
        }
        if(ymouse >= 22 && ymouse <= 23 ) {
            inputitem("참고서",7000);
        }
        if(ymouse >= 24 && ymouse <= 25) {
            inputitem("귀과권",10000);
        }
        if(ymouse >= 26 && ymouse <= 27) {
            inputitem("수험료",50000);
        }

    }
}
void inputitem(char *name, int money)
{

        if(player.i[9].name != NULL ){
                gotoxy(0,33);
                printf("가방이 꽉 찾습니다.");

        }
            for(int i=0; i<11; i++)
            {
                if(player.i[i].name == name){
                    player.i[i].number ++;
                    player.money -= money;
                    return;
                } else if(player.i[i].name == NULL){
                    player.i[i].name = name;
                    player.i[i].number++;
                    player.money -= money;
                    return;
                }
            }

}


void dimigoin()
{
    int groupIn = 0;
    int shopIn = 0;
    dimigoin_printing();
    checkmouse();
    if(groupIn) group();
    if(shopIn) shop();
    if(xmouse>=0 && xmouse <= 23 ){
        if(ymouse >=3 && ymouse <= 5){
            /*신청 트리거*/
            group();
            groupIn = 1;
            shopIn = 0;
        } else if(ymouse >=7 && ymouse <= 9){
            /*상점 트리거*/
            shop();
            groupIn = 0;
            shopIn = 1;
        }
    }
}

/**LEVEL SETTING**/

/**Tech FUNCTION**/
void checkmouse()
{
    DWORD mode;
    WORD key;
    COORD pos;

    int event;        // 마우스 이벤트에 이용
    int x;            // 마우스의 x좌표 저장소
    int y;            // 마우스의 y좌표 저장소

    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // 마우스 활성화
    GetConsoleMode(CIN,&mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

    while(1)
    {
        if(be_input())
       {
            if(get_input(&key,&pos) != 0 )
            {
              MOUSE_EVENT;
               x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
               y = pos.Y;
               xmouse = x; ymouse = y;
               return;
             }
         }
    }
}

void checkclick() ///클릭의 위치에 따른 실행범위 지정
{
    if(xmouse>=0 && xmouse <= 23) {
        if(ymouse>=0 && ymouse <= 2){
            gotoxy(0,4);
            printf("Welcome to Test1\n");

        }
    }
    if(xmouse>=25 && xmouse <= 47) {
        if(ymouse>=0 && ymouse <= 2){
            gotoxy(0,4);
            printf("Welcome to Test2\n");
        }
    }
    if(xmouse>=50 && xmouse <= 72) {
        if(ymouse>=0 && ymouse <= 2){
            gotoxy(0,4);
            printf("Welcome to Test3\n");
        }
    }
}

void resizeConsole(int width, int height) ///콘솔창 크기 설정
{
    char chtemp[100];
    sprintf(chtemp,"mode con cols=%d lines=%d",width, height);
    /*
        sprintf - 문자열 안에 원하는 변수를 삽입가능, (변수명, "명령문 %d",변수);
    */
    system(chtemp);
}
int be_input()
{
    INPUT_RECORD input_record;
    DWORD input_count;

    PeekConsoleInput(CIN, &input_record, 1, &input_count);
    return input_count;
}

int get_input(WORD *vkey, COORD *pos)
{
    INPUT_RECORD input_record;
    DWORD input_count;

    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch(input_record.EventType) {
    case MOUSE_EVENT:
        if(pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
            CONSOLE_SCREEN_BUFFER_INFO csbi;

            GetConsoleScreenBufferInfo(COUT,&csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;

            return MOUSE_EVENT;
        }
        break;

    }

//    FlushConsoleInputBuffer(CIN);
    return 0;
}

void gotoxy(int x, int y) ///좌표 설정
{
    COORD co = {x,y};
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE) ,
        co
    );
}

void clearCursor() ///커서 삭제
{
    CONSOLE_CURSOR_INFO cc;
    cc.bVisible = FALSE;
    cc.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cc);
}

void save_all()
{
    FILE *fp = fopen("save.bin","wb");
    fwrite(&player,sizeof(player),1,fp);
    fclose(fp);
}

void open_save()
{
    FILE *fp = fopen("save.bin","rb");
    if(fp == NULL){
        printf("저장된 파일이 없습니다!");
        return 0;
    }
    fread(&player,sizeof(player),1,fp);
    fclose(fp);
}

void times(int x)
{
    for(int i=0; i<x; i++){
        Sleep(1000);
    }
}

/**Tech FUNCTION**/

///////////////////////////////////////////////////////////////////

/**MAP PRINTTING**/
void menuplay() ///고정메뉴
{
    if(player.level == 1){
    gotoxy(0,0);
    printf("┌─────────────────────┐\n"); ///0,0 - 23,2
    gotoxy(0,1);
    printf("│        교실         │\n");
    gotoxy(0,2);
    printf("└─────────────────────┘\n");

    gotoxy(25,0);
    printf("┌─────────────────────┐\n"); ///25,0 - 47,2
    gotoxy(25,1);
    printf("│      디미고인       │\n");
    gotoxy(25,2);
    printf("└─────────────────────┘\n");
    } else if(player.level==2){
    gotoxy(0,0);
    printf("┌─────────────────────┐\n"); ///0,0 - 23,2
    gotoxy(0,1);
    printf("│        교실         │\n");
    gotoxy(0,2);
    printf("└─────────────────────┘\n");
    gotoxy(25,0);
    printf("┌─────────────────────┐\n"); ///25,0 - 47,2
    gotoxy(25,1);
    printf("│      디미고인       │\n");
    gotoxy(25,2);
    printf("└─────────────────────┘\n");
    gotoxy(50,0);
    printf("┌─────────────────────┐\n"); ///50,0 - 72,2
    gotoxy(50,1);
    printf("│        test         │\n");
    gotoxy(50,2);
    printf("└─────────────────────┘\n");
    gotoxy(75,0);
    printf("┌─────────────────────┐\n"); ///75,0 - 97,2
    gotoxy(75,1);
    printf("│        test         │\n");
    gotoxy(75,2);
    printf("└─────────────────────┘\n");
    } else if(player.level >= 3) {
    gotoxy(0,0);
    printf("┌─────────────────────┐\n"); ///0,0 - 23,2
    gotoxy(0,1);
    printf("│        교실         │\n");
    gotoxy(0,2);
    printf("└─────────────────────┘\n");
    gotoxy(25,0);
    printf("┌─────────────────────┐\n"); ///25,0 - 47,2
    gotoxy(25,1);
    printf("│      디미고인      │\n");
    gotoxy(25,2);
    printf("└─────────────────────┘\n");
    gotoxy(50,0);
    printf("┌─────────────────────┐\n"); ///50,0 - 72,2
    gotoxy(50,1);
    printf("│        test         │\n");
    gotoxy(50,2);
    printf("└─────────────────────┘\n");
    gotoxy(75,0);
    printf("┌─────────────────────┐\n"); ///75,0 - 97,2
    gotoxy(75,1);
    printf("│        test         │\n");
    gotoxy(75,2);
    printf("└─────────────────────┘\n");
    gotoxy(100,0);
    printf("┌─────────────────────┐\n"); ///100,0 - 122,2
    gotoxy(100,1);
    printf("│        test         │\n");
    gotoxy(100,2);
    printf("└─────────────────────┘\n");
    }


}
void all_print()
{
    gotoxy(50,4);
    printf("┌─────────────────────┐");
    gotoxy(50,5);
    printf("│        ITEM         │");
    gotoxy(50,6);
    printf("│                     │");
    gotoxy(50,7);
    printf("│ %s - %d개             ",player.i[0].name,player.i[0].number);
    gotoxy(50,8);
    printf("│                       ");
    gotoxy(50,9);
    printf("│ %s - %d개                   ",player.i[1].name,player.i[1].number);
    gotoxy(50,10);
    printf("│                       ");
    gotoxy(50,11);
    printf("│ %s - %d개                  ",player.i[2].name,player.i[2].number);
    gotoxy(50,12);
    printf("│                       ");
    gotoxy(50,13);
    printf("│ %s - %d개              ",player.i[3].name,player.i[3].number);
    gotoxy(50,14);
    printf("│                       ");
    gotoxy(50,15);
    printf("│ %s - %d개              ",player.i[4].name,player.i[4].number);
    gotoxy(50,16);
    printf("│                       ");
    gotoxy(50,17);
    printf("│ %s - %d개              ",player.i[5].name,player.i[5].number);
    gotoxy(50,18);
    printf("│                       ");
    gotoxy(50,19);
    printf("│ %s - %d개              ",player.i[6].name,player.i[6].number);
    gotoxy(50,20);
    printf("│                       ");
    gotoxy(50,21);
    printf("│ %s - %d개              ",player.i[7].name,player.i[7].number);
    gotoxy(50,22);
    printf("│                       ");
    gotoxy(50,23);
    printf("│ %s - %d개              ",player.i[8].name,player.i[8].number);
    gotoxy(50,24);
    printf("└─────────────────────┘");

    gotoxy(75,4);
    printf("┌─────────────────────┐");
    gotoxy(75,5);
    printf("│        INFO         │");
    gotoxy(75,6);
    printf("│                       ");
    gotoxy(75,7);
    printf("│ NAME : %s                    ",player.name);
    gotoxy(75,8);
    printf("│                       ");
    gotoxy(75,9);
    printf("│ GENDER : %s           ",player.gender);
    gotoxy(75,10);
    printf("│                       ");
    gotoxy(75,11);
    printf("│ GRADE  : %d학년  ",player.grade);
    gotoxy(75,12);
    printf("│                       ");
    gotoxy(75,13);
    printf("│ CLASS : %s          ",player.where);
    gotoxy(75,14);
    printf("│                       ");
    gotoxy(75,15);
    printf("│ Brief : %d          ",player.tbrief );
    gotoxy(75,16);
    printf("│                       ");
    gotoxy(75,17);
    printf("│ HAPPY : %d               ",player.happy);
    gotoxy(75,18);
    printf("│                       ");
    gotoxy(75,19);
    printf("│ TITLE : %s     ",player.title);
    gotoxy(75,20);
    printf("│                       ");
    gotoxy(75,21);
    printf("│ FRIEND : %d        ",player.friend);
    gotoxy(75,22);
    printf("│                       ");
    gotoxy(75,23);
    printf("│ MONEY : %d          ",player.money);
    gotoxy(75,24);
    printf("│                       ");
    gotoxy(75,25);
    printf("│ GROUP : %s          ",player.group);
    gotoxy(75,26);
    printf("│                       ");
    gotoxy(75,27);
    printf("│ HELPTIME : %d         ",player.helptime);
    gotoxy(75,28);
    printf("│                       ");
    gotoxy(75,29);
    printf("└─────────────────────┘");
}
void classroom_printing()
{
    menuplay();
    gotoxy(0,3);
    printf("┌─────────────────────┐");
    gotoxy(0,4);
    printf("│        수업         │");
    gotoxy(0,5);
    printf("└─────────────────────┘");
    gotoxy(0,7);
    printf("┌─────────────────────┐");
    gotoxy(0,8);
    printf("│        친구         │");
    gotoxy(0,9);
    printf("└─────────────────────┘");
}
void dimigoin_printing()
{
    menuplay();
    gotoxy(0,4);
    printf("┌─────────────────────┐");
    gotoxy(0,5);
    printf("│        신청         │");
    gotoxy(0,6);
    printf("└─────────────────────┘");
    gotoxy(0,8);
    printf("┌─────────────────────┐");
    gotoxy(0,9);
    printf("│        상점         │");
    gotoxy(0,10);
    printf("└─────────────────────┘");
}
void shop_printing()
{
    gotoxy(25,4);
    printf("┌─────────────────────┐");
    gotoxy(25,5);
    printf("│        상점         │");
    gotoxy(25,6);
    printf("┡─────────────────────┤");
    gotoxy(25,7);
    printf("│  음료수 - 700원     │");
    gotoxy(25,8);
    printf("┡─────────────────────┤");
    gotoxy(25,9);
    printf("│  아이스크림 - 500원 │" );
    gotoxy(25,10);
    printf("┡─────────────────────┤");
    gotoxy(25,11);
    printf("│  핫바 - 1300원      │");
    gotoxy(25,12);
    printf("┡─────────────────────┤");
    gotoxy(25,13);
    printf("│  찰떡피자 - 1500원  │");
    gotoxy(25,14);
    printf("┡─────────────────────┤");
    gotoxy(25,15);
    printf("│  팬류 - 500원       │");
    gotoxy(25,16);
    printf("┡─────────────────────┤");
    gotoxy(25,17);
    printf("│  공책 - 500원       │");
    gotoxy(25,18);
    printf("┡─────────────────────┤");
    gotoxy(25,19);
    printf("│  지우개 - 500원     │");
    gotoxy(25,20);
    printf("┡─────────────────────┤");
    gotoxy(25,21);
    printf("│  교과서 - 5000원    │");
    gotoxy(25,22);
    printf("┡─────────────────────┤");
    gotoxy(25,23);
    printf("│  참고서 - 7000원    │");
    gotoxy(25,24);
    printf("┡─────────────────────┤");
    gotoxy(25,25);
    printf("│  귀가권 - 10,000원  │");
    gotoxy(25,26);
    printf("┡─────────────────────┤");
    gotoxy(25,27);
    printf("│  수험료 - 50,000원  │");
    gotoxy(25,28);
    printf("┡─────────────────────┤");
    gotoxy(25,29);
    printf("│   추가예정          │");
    gotoxy(25,30);
    printf("└─────────────────────┘");

}

void group_printing()
{
    gotoxy(25,4);
    printf("┌─────────────────────┐");
    gotoxy(25,5);
    printf("│       동아리        │");
    gotoxy(25,6);
    printf("│                     │");
    gotoxy(25,7);
    printf("│     현재 동아리     │");
    gotoxy(25,8);
    printf("│                     │");
    gotoxy(25,9);
    printf("│ %s",player.group);
    gotoxy(25,10);
    printf("┡─────────────────────┤");
    gotoxy(25,11);
    printf("│     CODEBACKERY     │");
    gotoxy(25,12);
    printf("┡─────────────────────┤");
    gotoxy(25,13);
    printf("│        TRUST        │");
    gotoxy(25,14);
    printf("┡─────────────────────┤");
    gotoxy(25,15);
    printf("│       STELTH        │");
    gotoxy(25,16);
    printf("┡─────────────────────┤");
    gotoxy(25,17);
    printf("│         KUZE        │");
    gotoxy(25,18);
    printf("┡─────────────────────┤");
    gotoxy(25,19);
    printf("│         LUNA        │");
    gotoxy(25,20);
    printf("┡─────────────────────┤");
    gotoxy(25,21);
    printf("│         TED         │");
    gotoxy(25,22);
    printf("┡─────────────────────┤");
    gotoxy(25,23);
    printf("│      SoftWing       │");
    gotoxy(25,24);
    printf("┡─────────────────────┤");
    gotoxy(25,25);
    printf("│    DODAMPICTURS     │");
    gotoxy(25,26);
    printf("┡─────────────────────┤");
    gotoxy(25,27);
    printf("│       FREGIC        │");
    gotoxy(25,28);
    printf("┡─────────────────────┤");
    gotoxy(25,29);
    printf("│        TTL          │");
    gotoxy(25,30);
    printf("└─────────────────────┘");

}


/**MAP PRINTTING**/