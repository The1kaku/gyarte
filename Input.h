#ifndef INPUT_H
#define INPUT_H

#include "Globals.h"
#include "Player.h"
#include "Actions.h"
#include <vector>

struct InputProcessor
{
	private:
	IntMap colMap;
	bool* running;
	std::vector< Actor> *monsters;
	
	public:
	void setRunVar(bool *running) { this->running = running; }	
 	void updateColMap(IntMap colMap) { this->colMap = colMap; }
	void updateMonsterVec(std::vector< Actor> *monsters) { this->monsters = monsters; }
	
	int process(int input, Player &player);
};

#endif