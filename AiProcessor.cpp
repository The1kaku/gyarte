#include "AiProcessor.h"

int AiProcessor::processAi(Actor &actor, intMap colMap)
{
	switch(actor.aiType)
	{
		case 0:
		return 1;
		case 1:
		return circle(actor, colMap);
		default:
		return 0;
	}
}

int AiProcessor::circle(Actor &actor, intMap colMap)
{
	static int dx = 1, dy = 0; 
	
	int result = move(actor, colMap, dy, dx);

	if (result == 0)
	{
		if(dy == 0 && dx == 1)
		{
			dy = 1;
			dx = 0;
		}
		else if(dy == 1 && dx == 0)
		{
			dy = 0;
			dx = -1;
		}
		else if(dy == 0 && dx == -1)
		{
			dy = -1;
			dx = 0;
		}
		else
		{
			dy = 0;
			dx = 1;
		}
		
		result = move(actor, colMap, dy, dx);
	}

	return result;
}
