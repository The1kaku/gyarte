#ifndef LEVEL_H
#define LEVEL_H

#include <array>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Actor.h"
#include "Globals.h"

using std::vector; using std::string;

struct Level
{
	Level(int initType, string initVal);
	
	void createMapFromUrl(string url);
	void createMapFromString(string str); 
	const char *getMap() const;
	
	IntMap generateColMap();
	int getColMapPos(pos y, pos x) const;
	IntMap &getColMap();	
	int getColType(char c);
	IntMap initColMap();
	
	vector< string> map;
	IntMap colMap;	
	
	vector< Actor> monsters = {Actor(1, 1, 'M', true, 1), Actor(1, 4, 'N', true, 0)};
};

#endif