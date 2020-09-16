#include "Window.h"

Window::Window(int height, int width, int startY, int startX, bool hasBorder) 
	: height(height), width(width), startY(startY), startX(startX), hasBorder(hasBorder) { } 

Window::Window(int height, int width, int startY, int startX) 
	: Window(height, width, startY, startX, false) { }
	
WINDOW *Window::create()
{
	win = newwin(height, width, startY, startX); 
	return win;
} 


void Window::destroy()
{
	delwin(win);
}

void Window::displayLevel(Level level)
{
	waddstr(win, level.getMap());
}

void Window::displayActor(Actor actor)
{
	if (actor.visible)
	{
		wmove(win, actor.y, actor.x);
		waddch(win, actor.model);
	}
}

void Window::refresh()
{
	wrefresh(win);
}

void Window::clear()
{
	wclear(win);
}