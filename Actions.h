#ifndef ACTIONS_H
#define ACTIONS_H

#include "Globals.h"
#include "Actor.h"
#include "Level.h"

int checkCollision(intMap colMap, pos y, pos x); 

int move(Actor &actor, intMap colMap, int dy, int dx);


#endif