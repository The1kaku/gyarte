#include "AiProcessor.h"

int AiProcessor::processAi(Actor &actor, intMap colMap)
{
	switch(actor.aiType)
	{
		case 0:
		return 1;
		case 1:
		return backAndForth(actor, colMap);
		default:
		return 0;
	}
}

int AiProcessor::backAndForth(Actor &actor, intMap colMap)
{
	if (move(actor, colMap, 0, 1))
		return 1;
	if (move(actor, colMap, 1, 0))
		return 2;
	if (move(actor, colMap, 0, -1))
		return 3;
	if (move(actor, colMap, -1, 0))
		return 4;
	
	return 0; 
}
