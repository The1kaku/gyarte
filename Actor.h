#ifndef ACTOR_H
#define ACTOR_H

#include "Entity.h"
#include "Weapon.h"
#include "Armour.h"

struct Actor : public Entity
{
	Actor(pos y, pos x, char model, bool visible, int aiType) : Entity(y, x, model, visible), aiType(aiType), weapon(2, 0, 0), armour(2,2,2) { }
	Actor(pos y, pos x, char model) : Actor(y, x, model, true, 0) { }
	Actor() : Entity(), aiType(0) { } 
	
	int aiType;
	int health = 20;

	Weapon weapon;
	Armour armour;

};

#endif