#include "Input.h"
#include <curses.h>

int InputProcessor::process(int input, Player &player)
{
	switch (input)
	{
		case KEY_F(1):
			*running = false;
			return 1;
		case KEY_UP: 
			return attackMove(monsters, colMap, player.me, -1, 0);
		case KEY_RIGHT:
			return attackMove(monsters, colMap, player.me, 0, 1);
		case KEY_DOWN:
			return attackMove(monsters, colMap, player.me, 1, 0);
		case KEY_LEFT:
			return attackMove(monsters, colMap, player.me, 0, -1);
		default: 
			return 0;	
	}
	
	return 1;
}