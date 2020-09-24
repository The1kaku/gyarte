#ifndef ASTAR_H
#define ASTAR_H

#include "Level.h"
#include "Globals.h"
#include <vector>
#include <cmath>
#include <optional>

using std::vector;



struct Node
{
	Node(int y, int x, int parentY, int parentX) :
		y(y), x(x), parentY(parentY), parentX(parentX), g(0.0), h(0.0), f(0.0) {}
	Node(int y, int x) : Node(y, x, -1, -1) { }	
	Node() : Node(0, 0) {} 
	int y;
	int x;
	int parentY;
	int parentX;
	float g;
	float h;
	float f;
};

struct Astar
{
	Astar(int yStart, int xStart, int yFinish, int xFinish);
	
	Node dummy;
	Node startNode;
	Node finishNode;	
	
	vector< Node> openList;
	vector< Node> closedList;
	

	
	bool compareNodes(Node tester, Node dest)
	{
		return (tester.y == dest.y && tester.x == dest.x);
	}
	
	int calculateDistance(Node start, Node end) 
	{
		return (abs(start.x - end.x) + abs(start.y - end.y));
	}
	

	vector<Position> compute(IntMap colMap);

};

#endif