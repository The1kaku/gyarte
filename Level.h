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
	const char *getColMap() const;
	const int getCol(pos y, pos x) const;
	vector< vector< int>> &getCol();
	
	int getColType(char c);
	void createColMap();
	
	vector< string> map;
	vector< vector< int>> colMap;	
	
	vector< Actor> monsters = {Actor(1, 1, 'M', true, 1)};
};

#endif