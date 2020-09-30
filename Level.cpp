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
		initColMap();
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

IntMap Level::initColMap()
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
	return colMap;
}

IntMap &Level::getColMap()
{
	return colMap;
}

int Level::getColMapPos(pos y, pos x) const
{
	return colMap[y][x];
}

IntMap Level::generateColMap()
{
	IntMap res = colMap;
	for (auto monster : monsters)
	{
		res[monster.y][monster.x] = ((monster.visible) ? 1 : 0);
	}
	
	return res;
}