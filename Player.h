#ifndef PLAYER_H
#define PLAYER_H

#include "Gang.h"
#include "Map.h"
#include "Battle.h"

#include <stdio.h>
#include <string.h>

FILE * ConfigureFile;

int PlayerExp;

void Load();
void Save();

#endif