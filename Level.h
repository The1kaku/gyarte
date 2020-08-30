#include <string>
#include <vector>
#ifndef LevelHeader
#define LevelHeader
#include "Actor.h"
using std::string; using std::vector;

struct Level
{
	Level(pos height, pos width, string model) : height(height), width(width), model(model) { }
	string model;
	pos height, width;
	const string getModel() const;
	const char get(pos y, pos x) const;
	Actor monsters[1] {('%')};
};

#endif