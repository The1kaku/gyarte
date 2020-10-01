#include "Input.h"
#include <curses.h>

int InputProcessor::process(int input, Player &player)
{
	switch (input)
	{
		case KEY_F(1): case 'e':
			*running = false;
			return 1;
		case KEY_UP: case 'w':
			return attackMove(monsters, colMap, player.me, -1, 0);
		case KEY_RIGHT: case 's':
			return attackMove(monsters, colMap, player.me, 0, 1);
		case KEY_DOWN: case 'r':
			return attackMove(monsters, colMap, player.me, 1, 0);
		case KEY_LEFT: case 'a':
			return attackMove(monsters, colMap, player.me, 0, -1);
		default: 
			return 0;	
	}
	
	return 1;
}