#include <stdio.h>
#include "Gang.h"
#include "Battle.h"

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    char name;
    Gang enemy;
} Country;

typedef struct {
    int a[WIDTH+1][HEIGHT+1] = {0};
    int countriesNum = 0;
    Country countries[10];
} Map;

Map map;

void MapSelect();
void MapRender(int selected);