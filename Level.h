#include <string>
#ifndef LevelHeader
#define LevelHeader

using std::string;
typedef string::size_type pos;

struct Level
{
	Level(pos height, pos width, string model) : height(height), width(width), model(model) { }
	string model;
	pos height, width;
	const string getModel() const;
};

#endif