#ifndef ACTOR_H
#define ACTOR_H

#include "Entity.h"

struct Actor : public Entity
{
	Actor(pos y, pos x, char model, bool visible, unsigned aiType) : Entity(y, x, model, visible), aiType(aiType) { }
	Actor(pos y, pos x, char model) : Actor(y, x, model, true, 0) { }
	Actor() : Entity(), aiType(0) { } 
	
	unsigned aiType;
};

#endif