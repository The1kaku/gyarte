#ifndef INPUT_H
#define INPUT_H

#include "Globals.h"
#include "Player.h"
#include "Actions.h"

struct InputProcessor
{
	private:
	IntMap colMap;
	bool* running;
	
	public:
	void setRunVar(bool *running) { this->running = running; }	
 	void setColMap(IntMap colMap) { this->colMap = colMap; }
	
	int process(int input, Player &player);
};

#endif