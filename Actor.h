#ifndef ActorHeader
#define ActorHeader

#include "Entity.h"

class Actor: public Entity
{
	public:
	Actor(char model, pos y, pos x, int health, int strength, int speed); 
	Actor(char model, pos y, pos x);
	Actor(char model);
	Actor();
	int type;
	
	int health;
	int strength;
	int speed;
};

#endif