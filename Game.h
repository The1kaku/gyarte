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
	const pos PLAYERSTATS_WIN_HEIGHT = 10;
	deque<string> infoMessages;
	WINDOW *mainWin;
	WINDOW *infoWin;
	WINDOW *playerStatsWin;
	
	void loop();
	void init();
	void updateScreen(); 
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