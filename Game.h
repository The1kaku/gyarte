#ifndef GameHeader
#define GameHeader

#include "Player.h"
#include "Level.h"
#include <string>
#include <curses.h>
#include <deque>

using std::deque;

class Game
{
	Level level;
	Player player;
	bool running = true; 
	string infoMessage;
	const pos INFO_WIN_HEIGHT = 30;
	deque<string> infoMessages;
	WINDOW *main;
	WINDOW *info;
	
	void loop();
	void init();
	void updateScreen(); 
	int getInput();
	void manageInput();
	void updateInfoMessages(); 
	
	public:
	Game(char playerModel, pos levelHeight, pos levelWidth, string levelModel);
	Game(pos levelHeight, pos levelWidth, string levelModel);
	Game(char playerModel, string url);
	Game(string url);
	~Game();
	 
};

#endif