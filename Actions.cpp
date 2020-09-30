#include "Actions.h"

int checkCollision(IntMap colMap, pos y, pos x)
{ 
	return colMap[y][x];
}

int move(Actor &actor, IntMap colMap, int dy, int dx)
{
	if (actor.y + dy <= 0 || actor.x + dx <= 0 || actor.y + dy >= levelHeight || actor.x + dx >= levelWidth)
		return 0;
	if (checkCollision(colMap, actor.y + dy, actor.x + dx) == 0)
	{
		actor.y += dy;
		actor.x += dx;
		return 1;
	}
	return 0;
}


int attack(Actor &attacker, Actor &defender)
{
	defender.health -= attacker.attackPower;
	return 1;
}

int attackMove(std::vector< Actor> *defenders, IntMap colMap, Actor &actor, int dy, int dx)
{
	int newY = actor.y + dy;
	int newX = actor.x + dx;

	for (auto &defender : *defenders)
	{
		if (defender.y == newY && defender.x == newX)
		{
			return attack(actor, defender);
		}
	}
	
	return move(actor, colMap, dy, dx);
}

int attackMove(Actor &defender, IntMap colMap, Actor &actor, int dy, int dx)
{
	int newY = actor.y + dy;
	int newX = actor.x + dx;

	if (defender.y == newY && defender.x == newX)
	{
		return attack(actor, defender);
	}
	
	return move(actor, colMap, dy, dx);	
}