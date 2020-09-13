#include "Player.h"

void Player::move(Level& level, string& infoMessage, int dy, int dx)
{
	string nextTileInfo = "   ";
	bool isColliding = false;
	
	nextTileInfo[0] = level.get(y() + dy, x() + dx);
	Actor* defendingMonster; 

	for (auto& monster : level.monsters)
	{
		if (y() + dy == monster.y && x() + dx == monster.x)
		{
			nextTileInfo[1] = monster.model;
			defendingMonster = &monster;
			break;
		}
	}

	list<Item>::iterator itemIt = level.items.begin();
	for (; !level.items.empty() && itemIt != level.items.end(); ++itemIt)
	{
		if (y() + dy == itemIt->y && x() + dx == itemIt->x)
		{
			nextTileInfo[2] = itemIt->model;
			level.items.erase(itemIt);
			break;
		}
	}		
		
	if (nextTileInfo[1] == ' ')
		handleCollisionInput(infoMessage, isColliding, nextTileInfo[0]);
	else
		handleCombatInput(infoMessage, isColliding, defendingMonster, nextTileInfo[1]);
	handleItemInput(infoMessage, nextTileInfo[2]);
	
	infoMessage += "!\n";
	
	if(!isColliding)
	{
		me.y += dy;
		me.x += dx;		
	}	
}

void Player::handleCombatInput(string& infoMessage, bool& isColliding, Actor* defendingMonster, char info)
{
	switch (info)
	{
		case '%': case '&':
			isColliding = true;
			infoMessage = "You attacked ";
			infoMessage += defendingMonster->model;
			action.attack(me, *defendingMonster);
			infoMessage += ", monster now has: ";
			infoMessage += std::to_string(defendingMonster->health);
			infoMessage += " HP left";
			break;
	}
}

void Player::handleCollisionInput(string& infoMessage, bool& isColliding, char info)
{
	switch (info)
	{
		case '#': case '\0':
			infoMessage = "Could not move there";
			isColliding = true;
			break;
		default:
			infoMessage = "You moved";
			isColliding = false;
			break;
	}
}

void Player::handleItemInput(string& infoMessage, char info)
{
	switch (info)
	{
		case 'c':
			infoMessage += " and collected a coin";
			++coinage;
			break;
		default:
			break;	
	}
}
