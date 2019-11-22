#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string.h>

#include "Map.h"
#include "Battle.h"

void LoadPlayer(); 
void Load();
void EnemyLoad(int Ecode);
void Save();
void Debug();

FILE * ConfigureFile;
FILE * PlayerFile;

#endif