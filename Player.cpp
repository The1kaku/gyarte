#include "Player.h"

int Player::putInInventory(Item item)
{
	if (inventory.size() < inventorySize)
	{
		inventory.push_back(item);
		return 1;
	}
	return 0;	
}

int Player::putInInventory(Item item, size_t amount)
{
	if (inventory.size() <= inventorySize - amount)
	{
		for (size_t t = 0; t < amount; ++t)
		{
			inventory.push_back(item);
		}
		return 1;
	}
	return 0;
}