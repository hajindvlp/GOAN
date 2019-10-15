typedef struct {
    char name[101];
    int hp;
    int dg;
    int cost;
} Character;

typedef struct {
    int chracterNum = 0;
    Character characters[100];
    void (*upgrade)(int, int, int) = Upgrade;
} Gang;

Gang gang;

void Upgrade(int characterCode, int hpUp, int dgUp);