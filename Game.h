#ifndef GAME_H
#define GAME_H

#include "AiProcessor.h"
#include "Input.h"
#include "Window.h"
#include "Level.h"
#include <vector>
#include "Player.h"
#include "Globals.h"
#include "Astar.h"

using std::vector;

struct Game
{
	Game();
	~Game();
	
	AiProcessor aiProcessor;
	InputProcessor inProcessor;
	Player player;
	
	bool running = true;
	
	Level level;
	Window gameWin;
	Window playerWin;
	Window infoWin;
	
	void init();
	void loop();
};

#endif