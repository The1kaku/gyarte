#include "Player.h"

bool Player::testCollision(Level level, pos y, pos x)
{
	//if (y >= level.height || x >= level.width) return true;
	if (*(level.model.begin() + level.width * (this->y + y)	+ (this->x + x)) == '#') return true;
	return false;
}