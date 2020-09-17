#include "Game.h"

Game::Game() : 	gameWin(levelHeight, levelWidth + 1, 0, 0, true), 
				playerWin(20, 20, 0, 41, true), 
				infoWin(20, 20, 21, 21, true),
				level(1, "########\n#......#\n#......#\n#......#\n########")
{
	init();
	loop();
}

Game::~Game()
{
	gameWin.destroy();
	playerWin.destroy();
	infoWin.destroy();

	endwin();
}

void Game::init()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	 
	gameWin.create();
	playerWin.create();
	infoWin.create();
}

void Game::loop()
{
	while (getch() != 'e')
	{
		gameWin.clear();
		infoWin.clear();
		gameWin.addLevel(level);
		for (auto &monster : level.monsters)
		{
			aiProcessor.setColMap(level.generateColMap());
			infoWin.addInt(aiProcessor.processAi(monster));
			gameWin.addActor(monster);
		}
		gameWin.refresh();
		infoWin.refresh();
	}
}