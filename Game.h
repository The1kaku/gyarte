#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include <string>
#ifndef GameHeader
#define GameHeader

struct Game
{
	Game(char playerModel, pos levelHeight, pos levelWidth, string levelModel) : player(playerModel), level(levelHeight, levelWidth, levelModel) { }
	Player player;
	Level level;
	Enemy enemy;
};

#endif