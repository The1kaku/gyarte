#include "Game.h"
#include <iostream>


Game::Game(char playerModel, pos levelHeight, pos levelWidth, string levelModel) : player(playerModel), level(levelHeight, levelWidth, levelModel) 
{ 
	init();
}

Game::Game(pos levelHeight, pos levelWidth, string levelModel) : Game('@', levelHeight, levelWidth, levelModel) { }

Game::Game(char playerModel, string url) : player(playerModel), level(url) { init(); }

Game::Game(string url) : Game('@', url) { }

Game::~Game()
{
	getch();
	endwin();
}


void Game::init()
{
	initscr();
	noecho();
	
	mainWin = newwin(level.height + 2, level.width + 2, 0, 0);
	infoWin = newwin(INFO_WIN_HEIGHT, 45, level.height + 4, 0 );
	playerStatsWin = newwin(level.height + 2, 30, 0, level.width + 4);
	
	keypad(mainWin, true);
	
	loop();
}
void Game::loop()
{
	while (running)
	{
		manageInput();
		updateInfoMessages();
		updateScreen();		
	}
}

void Game::updateScreen()
{
	wclear(mainWin);
	waddstr(mainWin, level.model.c_str());
	for (auto monster : level.monsters)
		mvwaddch(mainWin, monster.y, monster.x, monster.model);
	for (auto item : level.items)
		mvwaddch(mainWin, item.y, item.x, item.model);
	mvwaddch(mainWin, player.y(), player.x(), player.model());
	wrefresh(mainWin);
	
	wclear(infoWin);
	for (auto message : infoMessages)
		waddstr(infoWin, message.c_str());
	wrefresh(infoWin);
	
	wclear(playerStatsWin);
	waddstr(playerStatsWin, "PLAYER STATS:\n\n  HEALTH: \n  STRENGTH: \n  SPEED:\n");
	mvwaddstr(playerStatsWin, 2, 14, player.health().c_str());
	mvwaddstr(playerStatsWin, 3, 14, player.strength().c_str());
	mvwaddstr(playerStatsWin, 4, 14, player.speed().c_str());
	wrefresh(playerStatsWin);
}

void Game::manageInput()
{
	switch (getch())
	{
		case 'w': 
			player.mvup(level, infoMessage);
			break;
		case 'a':
			player.mvlt(level, infoMessage);
			break;
		case 'r':
			player.mvdn(level, infoMessage);
			break;
		case 's':
			player.mvrt(level, infoMessage);
			break;
		case 'e':
			running = false;
			infoMessage = "Quit!";
			break;
		default:
			infoMessage = "Invalid Input!";
			break;
	}
}

void Game::updateInfoMessages()
{
	infoMessages.push_back(infoMessage);
	infoMessage.clear();
	if (infoMessages.size() > INFO_WIN_HEIGHT / 2)
		infoMessages.pop_front();	
}