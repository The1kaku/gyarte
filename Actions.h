#ifndef ACTIONS_H
#define ACTIONS_H

#include "Globals.h"
#include "Actor.h"
#include "Level.h"
#include <vector>

int checkCollision(IntMap colMap, pos y, pos x); 

int move(Actor &actor, IntMap colMap, int dy, int dx);

int attack(Actor &attacker, Actor &defender);

int attackMove(std::vector< Actor> *monsters, IntMap colMap, Actor &actor, int dy, int dx);

int attackMove(Actor &defender, IntMap colMap, Actor &actor, int dy, int dx);


#endif