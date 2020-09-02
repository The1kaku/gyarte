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
	main = newwin(level.height + 2, level.width + 2, 0, 0);
	info = newwin(INFO_WIN_HEIGHT, 45,(level.height + 4), 0 );
	keypad(main, true);
	
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
	wclear(main);
	waddstr(main, level.model.c_str());
	for (auto monster : level.monsters)
		mvwaddch(main, monster.y, monster.x, monster.model);
	for (auto item : level.items)
		mvwaddch(main, item.y, item.x, item.model);
	mvwaddch(main, player.y(), player.x(), player.model());
	wrefresh(main);
	
	wclear(info);
	for (auto message : infoMessages)
		waddstr(info, message.c_str());
	wrefresh(info);
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