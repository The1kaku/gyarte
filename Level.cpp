#include "Level.h"

Level::Level(int initType, string initVal)
{
	switch (initType)
	{
		case 0:
		//createMapFromUrl(string url);
		break;
		case 1:
		createMapFromString(initVal);
		createColMap();
		break;
		default:
		break;
	}
}

void Level::createMapFromString(string str)
{
	string::const_iterator strIt = str.cbegin();
	
	for (vector< string>::size_type rowCnt = 0; rowCnt != levelHeight; ++rowCnt)
	{
		map.push_back("");
		for (string::size_type colCnt = 0; colCnt != levelWidth; ++colCnt)
		{
			bool ended = strIt == str.cend();
			if (ended || *strIt == '\n')
			{
				map[rowCnt].insert(map[rowCnt].begin() + colCnt, (levelWidth - colCnt), ' ');
				if (!ended)
					++strIt;
				break;
			}
			else
			{
				map[rowCnt].push_back(*strIt);
				++strIt;
			}
		}
	}
}

const char *Level::getMap() const
{
	string res;
	
	for (vector< string>::const_iterator rowIt = map.cbegin(); rowIt != map.cend(); ++rowIt)
	{
		res.append(*rowIt);
		res.push_back('\n');
	}
	return res.c_str();
}

int Level::getColType(const char c)
{
	for (const auto soft : SOFTS)
	{
		if (c == soft)
			return 0;
	}
	return 1;
}

void Level::createColMap()
{
	for (vector< string>::const_iterator mapRowIt = map.cbegin(); mapRowIt != map.cend(); ++mapRowIt)
	{
		vector< int> row;
		for (string::const_iterator mapColIt = mapRowIt->cbegin(); mapColIt != mapRowIt->cend(); ++mapColIt)
		{
			row.push_back(getColType(*mapColIt));
		}
		colMap.emplace_back(row);
	}
}

const char *Level::getColMap() const
{
	string res;
	
	for (vector< vector< int>>::const_iterator rowIt = colMap.cbegin(); rowIt != colMap.cend(); ++rowIt)
	{
		for (vector< int>::const_iterator colIt = rowIt->cbegin(); colIt != rowIt->cend(); ++colIt)
		{
			res.push_back(*colIt + 48);
		}
		res.push_back('\n');
	}
	return res.c_str();
}

vector< vector< int>> &Level::getCol()
{
	return colMap;
}

const int Level::getCol(pos y, pos x) const
{
	return colMap[y][x];
}