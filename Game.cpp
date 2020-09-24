#include "Game.h"

Game::Game() : 	gameWin(levelHeight, levelWidth, 0, 0, true), 
				playerWin(20, 20, 0, 21, true), 
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
	
	inProcessor.setRunVar(&running);
	 
	gameWin.create();
	playerWin.create();
	infoWin.create();
}

void Game::loop()
{
	int c;
	/*while (running)
	{
		c = getch(); 
		gameWin.clear();
		infoWin.clear();
		gameWin.addLevel(level);
		inProcessor.setColMap(level.generateColMap(player.me));
		inProcessor.process(c, player);
		for (auto &monster : level.monsters)
		{
			aiProcessor.setColMap(level.generateColMap(player.me));
			infoWin.addInt(aiProcessor.processAi(monster));
			gameWin.addActor(monster);
		}
		gameWin.addActor(player.me);
		gameWin.refresh();
		infoWin.refresh();
	} 
	*/
	
	IntMap iMap = {	{0, 0, 0, 0, 0,}, 
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0}, 
					{0, 0, 0, 0, 0},				
					{0, 0, 0, 0, 0}
	};
	getch();
	infoWin.clear();
	gameWin.clear();
	playerWin.clear();
	vector< Position> path;
	
	Astar astar(4, 4, 0, 0);
	path = astar.compute(iMap);
	
	for (auto row : iMap)
	{
		for (auto i : row)
		{
			gameWin.addInt(i);
		}
		waddch(gameWin.win, '\n');
	}
	
	int i = 1;
	wprintw(playerWin.win, "PATH:");
	// wprintw(playerWin.win, std::to_string(path.size()).c_str());
	for (auto pos : path)
	{
		mvwprintw(playerWin.win, i, 0, "Node");
		playerWin.addInt(i++);
		wprintw(playerWin.win, ": [");
		wprintw(playerWin.win, std::to_string(pos.y).c_str());
		waddch(playerWin.win, ' ');
		wprintw(playerWin.win, std::to_string(pos.x).c_str());
		waddch(playerWin.win, ']');
	}
	playerWin.refresh();
	gameWin.refresh();
	getch();
}