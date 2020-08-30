#include "Game.h"


Game::Game(char playerModel, pos levelHeight, pos levelWidth, string levelModel) : player(playerModel), level(levelHeight, levelWidth, levelModel) 
{ 
	initscr();
	noecho();
	main = newwin(20, 20, 0, 0);
	info = newwin(20, 30, 0, 20);
	keypad(main, true);
	
	loop();
}

Game::Game(pos levelHeight, pos levelWidth, string levelModel) : Game('@', levelHeight, levelWidth, levelModel) { }

Game::~Game()
{
	getch();
	endwin();
}

void Game::loop()
{
	while (running)
	{
		infoMessage += manageInput();
		//handleAi();
		updateScreen();		
		infoMessage.clear();
	}

}

void Game::updateScreen()
{
	wclear(main);
	waddstr(main, level.getModel().c_str());
	for (auto monster : level.monsters)
		mvwaddch(main, monster.y, monster.x, monster.model);
	mvwaddch(main, player.y(), player.x(), player.model());
	wrefresh(main);
	
	waddstr(info, infoMessage.c_str());
	waddch(info, '\n');
	wrefresh(info);
}

int Game::getInput()
{
	return getch();
}

string Game::manageInput()
{
	switch (getInput())
	{
		case 'w': 
			return player.mvup(level);
		case 'a':
			return player.mvlt(level);
		case 'r':
			return player.mvdn(level);
		case 's':
			return player.mvrt(level);
		case 'e':
			running = false;
			return "quit";
		default:
			return "Invalid input";
	}
}