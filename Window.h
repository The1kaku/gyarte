#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>
#include "Actor.h"
#include "Level.h"

struct Window
{
	Window(int height, int width, int startY, int startX, bool hasBorder); 
	Window(int height, int width, int startY, int startX);
	
	WINDOW *create();
	void destroy();
	
	void displayLevel(Level level);
	void displayActor(Actor actor);
	void refresh();
	void clear();
	
	const int height, width, startY, startX;
	const bool hasBorder;
	WINDOW* win;
};



#endif