#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include "Battle.h"

#include <stdio.h>
#include <string.h>

FILE * ConfigureFile;

void Load();
void EnemyLoad(int Ecode);
void Save();
void Debug();

#endif