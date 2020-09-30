#ifndef AI_PROCESSOR_H
#define AI_PROCESSOR_H

#include "Globals.h"
#include "Actor.h"
#include "Level.h"
#include "Actions.h"
#include <vector>
#include "astar.h"

class AiProcessor
{
	private:
	IntMap colMap;
	Actor *player;

	public:
	
	AiProcessor(Actor* player) : player(player) {}
	void updateColMap(IntMap colMap) { this->colMap = colMap; }
	void updatePlayer(Actor* player) { this->player = player; }
	
	int processAi(Actor &actor);
	
	int circle(Actor &actor);
};

#endif