#ifndef ACTIONS_H
#define ACTIONS_H

#include "Globals.h"
#include "Actor.h"
#include "Level.h"

int checkCollision(IntMap colMap, pos y, pos x); 

int move(Actor &actor, IntMap colMap, int dy, int dx);


#endif