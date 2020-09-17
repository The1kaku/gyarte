#ifndef AI_PROCESSOR_H
#define AI_PROCESSOR_H

#include "Globals.h"
#include "Actor.h"
#include "Level.h"
#include "Actions.h"
#include <vector>

using std::vector;

class AiProcessor
{
	private:
	IntMap colMap;

	public:
	void setColMap(IntMap colMap) { this->colMap = colMap; }
	
	int processAi(Actor &actor);
	
	int circle(Actor &actor);
};

#endif