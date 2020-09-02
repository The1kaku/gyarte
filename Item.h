#ifndef ItemHeader
#define ItemHeader

#include "Entity.h"

class Item : public Entity
{
	int type;
	public:
	Item(int newType, char newModel, pos newY, pos newX) : type(newType), Entity(newModel, newY, newX) { }
};

#endif