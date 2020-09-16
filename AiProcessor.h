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
	intMap colMap;

	public:
	void setColMap(intMap colMap) { this->colMap = colMap; }
	
	int processAi(Actor &actor, intMap colMap);
	
	int backAndForth(Actor &actor, intMap colMap);
};

#endif