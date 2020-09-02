#include "Player.h"

void Player::move(Level level, string& infoMessage, int dy, int dx)
{
	string nextTileInfo = "  ";
	bool isColliding = false;
	
	nextTileInfo[0] = level.get(y() + dy, x() + dx);
	
	for (auto monster : level.monsters)
		if (y() + dy == monster.y && x() + dx == monster.x)
			nextTileInfo[0] = monster.model;
		
	for (auto item : level.items)
		if (y() + dy == item.y && x() + dx == item.x)
			nextTileInfo[1] = item.model;		
		
	
	handleCollisionInput(infoMessage, isColliding, nextTileInfo[0]);	
	handleItemInput(infoMessage, nextTileInfo[1]);
	
	infoMessage += "!\n";
	
	if(!isColliding)
	{
		me.y += dy;
		me.x += dx;		
	}	
}

void handleCollisionInput(string& infoMessage, bool& isColliding, char info)
{
	switch (info)
	{
		case '#': case '\0':
			infoMessage = "Could not move there";
			isColliding = true;
			break;
		case '%':
			isColliding = true;
			infoMessage = "You attacked a monster";
			break;
		default:
			infoMessage = "You moved";
			isColliding = false;
			break;
	}
}

void handleItemInput(string& infoMessage, char info)
{
	switch (info)
	{
		case 'c':
			infoMessage += " and collected a coin";
			break;
		default:
			break;	
	}
}
