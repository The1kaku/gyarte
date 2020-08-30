#include "Level.h"
#include "Actor.h"
#include <string>
#ifndef PlayerHeader
#define PlayerHeader

class Player
{
	Actor me;
	
	string move(Level level, int y, int x);
	
	public:
	Player(char model) : me(model) { }
	
	string mvup(Level level) { return move(level, -1, 0); }
	string mvdn(Level level) { return move(level, 1, 0); }
	string mvlt(Level level) { return move(level, 0, -1); }
	string mvrt(Level level) { return move(level, 0, 1); }
	pos x() const { return me.x; }
	pos y() const { return me.y; }
	char model() const { return me.model; }
};

#endif