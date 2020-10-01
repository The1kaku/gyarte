#include "Actions.h"
#include <cmath>

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

int getDamage(int damage, int armour)
{
	double val = 0;
	if (armour >= 0)
	{
		val = damage * (100.0 / (100.0 + armour));
	}
	else
	{
		val = damage * (2.0 - (100.0 / (100.0 - armour)));
	}
	return round(val);
}

int attack(Actor &attacker, Actor &defender)
{
	int val = 0;
	val += getDamage(attacker.weapon.impact, defender.armour.impact);
	val += getDamage(attacker.weapon.pierce, defender.armour.pierce);
	val += getDamage(attacker.weapon.slash, defender.armour.slash);
	defender.health -= val;
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