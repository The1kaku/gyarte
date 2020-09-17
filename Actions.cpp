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