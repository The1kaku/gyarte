#include "Level.h"
#include "Actor.h"
#include "Action.h"
#include <string>
#ifndef PlayerHeader
#define PlayerHeader

class Player
{
	Actor me;
	Action action;
	void move(Level&, string&, int, int);
	int coinage;	
	
	public:
	Player(char model) : me(model), coinage(0) { }
	
	void mvup(Level& level, string& infoMessage) { move(level, infoMessage, -1,  0); }
	void mvdn(Level& level, string& infoMessage) { move(level, infoMessage,  1,  0); }
	void mvlt(Level& level, string& infoMessage) { move(level, infoMessage,  0, -1); }
	void mvrt(Level& level, string& infoMessage) { move(level, infoMessage,  0,  1); }
	pos x() const { return me.x; }
	pos y() const { return me.y; }
	string health() const { return std::to_string(me.health); }
	string strength() const { return std::to_string(me.strength); }
	string speed() const { return std::to_string(me.speed); }
	string coins() const { return std::to_string(coinage); }
	char model() const { return me.model; }
	void handleCollisionInput(string&, bool&, char);
	void handleCombatInput(string&, bool&, Actor*, char);
	void handleItemInput(string&, char);
};


#endif