#include "AiProcessor.h"

#include <curses.h>

int AiProcessor::processAi(Actor &actor)
{
	switch(actor.aiType)
	{
		case 0:
		return 1;
		case 1:
		return circle(actor);
		default:
		return 0;
	}
}

int AiProcessor::circle(Actor &actor)
{
	Astar astar(actor.y, actor.x, player->y, player->x);
	vector< Position> path;
	path = astar.compute(colMap); 
	
	if (path.size() > 0)
	{
		attackMove(*player, colMap, actor, -path.back().y, path.back().x);
		return 1;
	}

	return 0;
}
