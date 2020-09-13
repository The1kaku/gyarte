#include <string>
#include <vector>
#ifndef LevelHeader
#define LevelHeader
#include "../EntityClasses/Actor.h"
#include "../EntityClasses/Item.h"
#include <fstream>
#include <list>
#include <iostream>
#include <algorithm>
using std::string; using std::list; using std::ifstream;

struct Level
{
	Level(pos height, pos width, string model) : height(height), width(width), model(model) { }
	Level(string url);
	string model;
	string collisionModel;
	pos height, width;
	const string getModel() const;
	const char get(pos y, pos x) const;
	
	list<Actor> monsters;
	list<Item> items; 
	
	bool generateEntity(char, pos, pos);
};

#endif