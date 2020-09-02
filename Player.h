#include "Level.h"
#include "Actor.h"
#include <string>
#ifndef PlayerHeader
#define PlayerHeader

class Player
{
	Actor me;
	
	void move(Level, string&, int, int);
	
	public:
	Player(char model) : me(model) { }
	
	void mvup(Level level, string& infoMessage) { move(level, infoMessage, -1,  0); }
	void mvdn(Level level, string& infoMessage) { move(level, infoMessage,  1,  0); }
	void mvlt(Level level, string& infoMessage) { move(level, infoMessage,  0, -1); }
	void mvrt(Level level, string& infoMessage) { move(level, infoMessage,  0,  1); }
	pos x() const { return me.x; }
	pos y() const { return me.y; }
	char model() const { return me.model; }
};

	void handleCollisionInput(string&, bool&, char);
	void handleItemInput(string&, char);
#endif