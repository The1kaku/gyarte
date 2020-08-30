#include "Game.h"
#include <curses.h>
#include <unistd.h>

Game game('@', 6, 10, "###########::::::::##::::::::##::::::::##::::::::###########");
bool running = true;

void handleInput()
{
	char input = getch();
	switch (input)
	{
		case 'a':
			if (!game.player.testCollision(game.level, 0, -1)) --game.player.x;
			break;
		case 'w':
			if (!game.player.testCollision(game.level, -1, 0)) --game.player.y;
			break;
		case 'r':
			if (!game.player.testCollision(game.level, 1, 0)) ++game.player.y;
			break;
		case 's':
			if (!game.player.testCollision(game.level, 0, 1)) ++game.player.x;
			break;
		case 'e':
			running = false;
			break;
		default:
			break;
	}
}

void handleAi()
{
	if (game.enemy.y > game.player.y) --game.enemy.y;
	else if (game.enemy.y < game.player.y) ++game.enemy.y;
	else if (game.enemy.x > game.player.x) --game.enemy.x;
	else if (game.enemy.x < game.player.x) ++game.enemy.x;
	else mvaddstr(20, 20, "You lost!");
}

void updateScreen()
{
	clear();
	addstr(game.level.getModel().c_str());
	mvaddch(game.player.y, game.player.x, game.player.model);
	mvaddch(game.enemy.y, game.enemy.x, game.enemy.model);
	refresh();
}

main()
{
	initscr();
	noecho();
	
	while(running)
	{	
		handleInput();
		handleAi();
		updateScreen();
	}
	
	endwin();
	return 0;
}