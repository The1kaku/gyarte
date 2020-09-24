#include "Astar.h"
#include <algorithm>
#include "curses.h"

Astar::Astar(int yStart, int xStart, int yFinish, int xFinish)
	: startNode(yStart, xStart, -1, -1), finishNode(yFinish, xFinish)
{ }	

vector< Position> Astar::compute(IntMap colMap)
{
	vector< Position> res;
	
	openList.push_back(startNode);

	int i = 1;
	
	while (!openList.empty())
	{
		clear();
		mvprintw(28, 0, "IntMap size = {");
		printw(std::to_string(colMap.size()).c_str());
		addch(',');
		printw(std::to_string(colMap.front().size()).c_str());
		addch('}');
		mvprintw(29, 0, "IterationNum = ");
		printw(std::to_string(i).c_str());
		mvprintw(30, 0, "OpenListSize = ");
		printw(std::to_string(openList.size()).c_str());
		int idxNodeP = 1;
		for (auto node : openList)
		{	
			mvprintw(30 + idxNodeP, 0, "Node = {");
			printw(std::to_string(node.y).c_str());
			addch(',');
			printw(std::to_string(node.x).c_str());
			printw("} (");
			printw(std::to_string(node.parentY).c_str());
			addch(',');
			printw(std::to_string(node.parentX).c_str());
			printw("), g = ");
			printw(std::to_string(node.g).c_str());
			printw(", h = ");
			printw(std::to_string(node.h).c_str());
			printw(", f = ");
			printw(std::to_string(node.f).c_str());
	
			idxNodeP++;
		}
		printw("\nDone!");
		refresh();
		i++;
		getch();
	

		// currentNode is the node with the lowest f value.
		// remove currentNode from openList.
		// add it to closedList 
		
		Node currentNode = openList.front();
		vector< Node>::iterator currentNodeIt = openList.begin();

		for (vector< Node>::iterator it = openList.begin(); it != openList.end(); ++it)
		{
			if (it->f < currentNode.f)
			{
				currentNode = *it; 
				currentNodeIt = it;
			}
		}
		openList.erase(currentNodeIt);
		closedList.emplace_back(currentNode.y, currentNode.x, currentNode.parentY, currentNode.parentX);
		
		// if currentNode is the goal, return
		if (compareNodes(currentNode, finishNode))
		{
			Node current = currentNode;
			
			while (current.parentY != -1 && current.parentX != -1)
			{
				res.emplace_back(current.parentY - current.y, current.x - current.parentX);
				for (auto &closedNode : closedList)
				{
					if (closedNode.y == current.parentY && closedNode.x == current.parentX)
						current = closedNode;
				}
			}	

			std::reverse(res.begin(), res.end());

			return res;
		}

		// genChildren
		vector< Node> children;

		children = {
			Node(currentNode.y - 1, currentNode.x, currentNode.y, currentNode.x),
			Node(currentNode.y, currentNode.x + 1, currentNode.y, currentNode.x),
			Node(currentNode.y + 1, currentNode.x, currentNode.y, currentNode.x),
			Node(currentNode.y, currentNode.x - 1, currentNode.y, currentNode.x)
		};

		for (auto child : children)
		{
			if (child.y < 0 || child.x < 0 || child.y >= colMap.size() || child.x >= colMap.front().size())
				continue;
			if (colMap[child.y][child.x] == 1)
				continue;
			bool foundInClosed = false;
			for (auto node : closedList)
				if (compareNodes(node, child))
					foundInClosed = true;
			if (foundInClosed)
				continue;
			
			// create g, h and f costs
			child.g = currentNode.g + 1;
			child.h = calculateDistance(child, finishNode);
			child.f = child.g + child.h;

			// Check if already in openList	
			bool hasBetterAlt = false;
			for (auto node : openList)
			{
				if (compareNodes(node, child) && node.g <= child.g )
				{
					hasBetterAlt = true;
				}
			}
			if (hasBetterAlt)
				continue;
		
			openList.push_back(child);
		}	
	}
	return res;
}