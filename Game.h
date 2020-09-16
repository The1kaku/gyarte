#ifndef GAME_H
#define GAME_H

#include "AiProcessor.h"
#include "Window.h"
#include "Level.h"
#include <vector>

using std::vector;

struct Game
{
	Game();
	~Game();
	
	AiProcessor aiProcessor;
	
	Level level;
	Window gameWin;
	Window playerWin;
	Window infoWin;
	
	void init();
	void loop();
};

#endif