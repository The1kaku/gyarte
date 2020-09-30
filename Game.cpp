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

void Game::clearWindows()
{
	gameWin.clear();
	infoWin.clear();
	playerWin.clear();
}

void Game::playerTurn()
{
	if (player.me.health <= 0)
	{
		clear();
		printw("You lost!");
		running = false;
		getch();
	}
	else 
	{
		int c = getch(); 
	
		inProcessor.updateColMap(level.generateColMap());
		inProcessor.updateMonsterVec(&(level.monsters));
		inProcessor.process(c, player);
		
		gameWin.addActor(player.me);
	}
}

void Game::aiTurn()
{
	aiProcessor.updatePlayer(&(player.me));

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
			infoWin.addInt(aiProcessor.processAi(*monster));
			gameWin.addActor(*monster);
			++monster;
		}	
	}
}

void Game::updateInfo()
{
	static int cnt = 0;
	infoWin.addStr("\nTurn_Count: ");
	infoWin.addInt(cnt++);
	infoWin.addStr("\nPlayer_HP: ");
	infoWin.addInt(player.me.health);
}

void Game::refreshWindows()
{
	playerWin.refresh();
	gameWin.refresh();
	infoWin.refresh();
}

void Game::loop()
{
	while (running)
	{
		clearWindows();
		
		gameWin.addMap(currMap);
	
		playerTurn();

		aiTurn();
		
		updateInfo();
		
		refreshWindows();
	} 
}