#ifndef GameHeader
#define GameHeader

#include <vector>
#include "Player.h"
#include "Level.h"
#include <string>
#include <curses.h>
#include <vector>

class Game
{
	Level level;
	Player player;
	bool running = true; 
	string infoMessage;
	WINDOW *main;
	WINDOW *info;
	
	void updateScreen(); // updates the screen
	int getInput();
	string manageInput();
	
	public:
	Game(char playerModel, pos levelHeight, pos levelWidth, string levelModel);
	Game(pos levelHeight, pos levelWidth, string levelModel);
	~Game();
	void loop(); // Starts the game loop
};

#endif