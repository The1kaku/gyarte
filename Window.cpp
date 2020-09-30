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

void Window::addLevel(Level level)
{
	waddstr(win, level.getMap());
}

void Window::addActor(Actor actor)
{
	if (actor.visible)
	{
		wmove(win, actor.y, actor.x);
		waddch(win, actor.model);
	}
}

void Window::addStr(string str)
{
	wprintw(win, str.c_str());
}

void Window::addMap(string map)
{
	addStr(map);
}

void Window::addch(int c)
{
	waddch(win, c);
}

void Window::addInt(int i)
{
	waddstr(win, std::to_string(i).c_str());
}

void Window::refresh()
{
	wrefresh(win);
}

void Window::clear()
{
	wclear(win);
}