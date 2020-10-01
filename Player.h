#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "Item.h"
#include <vector>

struct Player
{
	Player(pos y, pos x, char model, bool visible, int inventorySize) : me(y, x, model, visible, -1), inventorySize(inventorySize) { }
	Player(pos y, pos x) : Player(y, x, '@', true, 5) { }
	Player() : Player(1, 1) { }
	Actor me;
	
	int inventorySize;
	std::vector< Item> inventory;
	
	int putInInventory(Item item);
	int putInInventory(Item item, size_t amount);
	
	
	int gold = 0;
	int magicProwess = 0;	
};

#endif