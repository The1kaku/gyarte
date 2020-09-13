#ifndef ItemHeader
#define ItemHeader

#include "Entity.h"

class Item : public Entity
{
	public:
	Item(char newModel, pos newY, pos newX) : Entity(newModel, newY, newX) { }
};

#endif