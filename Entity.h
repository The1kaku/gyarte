#ifndef EntityHeader
#define EntityHeader
#include <string>

using std::string;
typedef string::size_type pos;
class Entity 
{
	public:
	Entity(char newModel, pos newX, pos newY) : x(newX), y(newY), model(newModel) { }
	Entity(char newModel) : Entity(newModel, 1, 1) { }
	pos x, y;
	char model;
};

#endif