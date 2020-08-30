#include "Player.h"

string Player::move(Level level, int dy, int dx)
{
	char next = level.get(y() + dy, x() + dx);
	for (auto monster : level.monsters)
		if (y() + dy == monster.y && x() + dx == monster.x)
			next = monster.model;
		
	switch (next)
	{
		case '#': case '\0':
			return "Could not move there!";
		case '%':
			return "You attacked a monster!";
		default:
			me.y += dy;
			me.x += dx;
			return "You moved";
	}
}