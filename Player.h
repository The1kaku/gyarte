#include "Level.h"
#ifndef PlayerHeader
#define PlayerHeader

struct Player
{
	Player(char model) : model(model) { }
	char model ;
	pos x = 1, y = 1;
	bool testCollision(Level level, pos y, pos x);
};

#endif