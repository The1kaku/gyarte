#include <string>
#include <vector>
#ifndef LevelHeader
#define LevelHeader
#include "Actor.h"
#include "Item.h"
#include <fstream>
#include <curses.h>
#include <iostream>
#include <algorithm>
using std::string; using std::vector; using std::ifstream;

struct Level
{
	Level(pos height, pos width, string model) : height(height), width(width), model(model) { }
	Level(string url);
	string model;
	string collisionModel;
	pos height, width;
	const string getModel() const;
	const char get(pos y, pos x) const;
	Actor monsters[1] {('%')};
	Item items[1] {Item(1, 'c', 3, 3)};
};

#endif