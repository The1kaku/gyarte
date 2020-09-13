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
	infoWin = newwin(INFO_WIN_HEIGHT, 80, level.height + 4, 0 );
	playerStatsWin = newwin(level.height + 4, 30, 0, level.width + 4);
	monsterStatsWin = newwin(level.height + 4, 30, 0, level.width + 30);
	
	keypad(mainWin, true);
	
	loop();
}
void Game::loop()
{
	while (running)
	{
		manageInput();
		updateInfoMessages();
		updateMonsters();
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
	waddstr(playerStatsWin, "PLAYER STATS:\n\n  HEALTH:\n  STRENGTH:\n  SPEED:\n  COINS:\n  ");
	mvwaddstr(playerStatsWin, 2, 14, player.health().c_str());
	mvwaddstr(playerStatsWin, 3, 14, player.strength().c_str());
	mvwaddstr(playerStatsWin, 4, 14, player.speed().c_str());
	mvwaddstr(playerStatsWin, 5, 14, player.coins().c_str());

	wrefresh(playerStatsWin);
	
	wclear(monsterStatsWin);
	waddstr(monsterStatsWin, "MONSTER STATS:\n\n  NUMMON:\n");
	mvwaddstr(monsterStatsWin, 2, 14, std::to_string(level.monsters.size()).c_str());
	wmove(monsterStatsWin, 3, 2);
	int y = 3;
	for (auto monster : level.monsters)
	{
		waddch(monsterStatsWin, monster.model);
		waddstr(monsterStatsWin, " {");
		waddstr(monsterStatsWin, std::to_string(monster.y).c_str());
		waddstr(monsterStatsWin, ", ");
		waddstr(monsterStatsWin, std::to_string(monster.x).c_str());
		waddstr(monsterStatsWin, "} : HP(");
		waddstr(monsterStatsWin, std::to_string(monster.health).c_str());
		waddstr(monsterStatsWin, ")");
		++y;
		wmove(monsterStatsWin, y, 2);
	}
	wrefresh(monsterStatsWin);	
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
			infoMessage = "Quit!\n";
			break;
		default:
			infoMessage = "Invalid Input!\n";
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

void Game::updateMonsters()
{
	list<Actor>::iterator monsterIterator = level.monsters.begin();
	for (; !level.monsters.empty() && monsterIterator != level.monsters.end(); ++monsterIterator)
		if (monsterIterator->health <= 0) 
			monsterIterator = level.monsters.erase(monsterIterator);	
}