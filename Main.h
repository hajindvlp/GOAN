#define WIDTH 50
#define HEIGHT 50

typedef struct {
    char name[101];
    int hp;
    int dg;
    int cost;
} Character;

typedef struct {
    int chracterNum = 0;
    Character characters[100];
} Gang;

typedef struct {
    char name[101];
    int price;
} Item;

Gang gang;