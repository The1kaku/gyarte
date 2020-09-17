#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

struct Item : public Entity
{
	Item(pos y, pos x, char model, bool visible, string name) : Entity(y, x, model, visible), name(name) { }
	Item(pos y, pos x, char model, string name) : Item(y, x, model, true, name) { }
	Item() : Entity(), name("") { }
	
	string name;
};

#endif