#include "Game.h"

Game::Game() : 	gameWin(levelHeight, levelWidth, 0, 0, true), 
				playerWin(20, 20, 0, 21, true), 
				infoWin(20, 20, 21, 21, true),
				level(1, "########\n#......#\n#..##..#\n#..##..#\n#......#\n########"),
				aiProcessor(&(player.me))
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
	 
	for (auto str : level.map)
	{
		currMap.append(str);
	}
	gameWin.create();
	playerWin.create();
	infoWin.create();
}

void Game::loop()
{
	int c;
	int cnt = 0;
	player.me.health = 40;
	while (running)
	{
		c = getch(); 
		gameWin.clear();
		infoWin.clear();
		playerWin.clear();
		// gameWin.addLevel(level);
		wprintw(gameWin.win, currMap.c_str());
		inProcessor.setColMap(level.generateColMap());
		inProcessor.setMonsterVec(&(level.monsters));
		inProcessor.process(c, player);
		aiProcessor.updatePlayer(&(player.me));
		for (auto row : level.colMap)
		{
			for (auto i : row)
			{
				playerWin.addInt(i);
			}
			waddch(playerWin.win, '\n');
		}
		for (std::vector< Actor>::iterator monster = level.monsters.begin(); monster != level.monsters.end(); )
		{
			if (monster->health <= 0)
			{
				monster = level.monsters.erase(monster);
				continue;
			}
			else
			{
				aiProcessor.updateColMap(level.generateColMap());
				infoWin.addch('I');
				infoWin.addch(':');
				infoWin.addch(' ');
				infoWin.addInt(aiProcessor.processAi(*monster));
				gameWin.addActor(*monster);
				++monster;
			}	
		}
		wprintw(infoWin.win, "\nCnt: ");
		infoWin.addInt(cnt++);
		wprintw(infoWin.win, "\nHP: ");
		infoWin.addInt(player.me.health);
		gameWin.addActor(player.me);
		playerWin.refresh();
		gameWin.refresh();
		infoWin.refresh();
		
		if (player.me.health <= 0)
		{
			clear();
			printw("You lost!");
			running = false;
			getch();
		}
	} 
}