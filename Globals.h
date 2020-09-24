#ifndef GLOBALS_H
#define GLOBALS_H

#include <array>
#include <vector>

typedef size_t pos;
typedef std::vector< std::vector<int>> IntMap;

constexpr unsigned levelWidth = 16, levelHeight = 16;
constexpr std::array< int, 2> SOFTS {'.', ':'};

struct Position
{
	Position(int y, int x) : y(y), x(x) { }
	Position() : Position(0, 0) { }	
	int y;
	int x;
};
#endif