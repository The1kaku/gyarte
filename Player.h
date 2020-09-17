#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "Item.h"
#include <vector>

using std::vector;

struct Player
{
	Player(pos y, pos x, char model, bool visible, int inventorySize) : me(y, x, model, visible, 0), inventorySize(inventorySize) { }
	Player(pos y, pos x) : Player(y, x, '@', true, 5) { }
	Player() : Player(1, 1) { }
	Actor me;
	
	int inventorySize;
	vector< Item> inventory;
	
	int putInInventory(Item item);
	int putInInventory(Item item, size_t amount);
};

#endif