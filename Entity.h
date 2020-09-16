#ifndef ENTITY_H
#define ENTITY_H

#include "Globals.h"

struct Entity
{
	Entity(pos y, pos x, char model, bool visible) : y(y), x(x), model(model), visible(visible) { }
	Entity(pos y, pos x, char model) : Entity(y, x, model, true) { } 
	Entity() : Entity(0, 0, ' ', true) { }
	
	pos y, x;
	char model;
	bool visible; 
};

#endif