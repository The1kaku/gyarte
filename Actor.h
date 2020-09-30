#ifndef ACTOR_H
#define ACTOR_H

#include "Entity.h"

struct Actor : public Entity
{
	Actor(pos y, pos x, char model, bool visible, int aiType) : Entity(y, x, model, visible), aiType(aiType) { }
	Actor(pos y, pos x, char model) : Actor(y, x, model, true, 0) { }
	Actor() : Entity(), aiType(0) { } 
	
	int aiType;
	int health = 20;
	int attackPower = 2;
};

#endif