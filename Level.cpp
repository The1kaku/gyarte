#include "Level.h"

Level::Level(string url) : height(0), width(0)
{
	string line;
	ifstream newLevel(url);

	if (newLevel.is_open())
	{
		while (getline(newLevel, line))
			model += line += '\n';
		
		newLevel.close();
		
		string::const_iterator it = model.cbegin();
		while (it != model.cend())
		{
			if (*it++ != '\n')
				++width;
			else
				break;
		}
		
		for (auto c : model)
			if (c == '\n')
				++height;
			
		collisionModel = model;	
		collisionModel.erase(std::remove(collisionModel.begin(), collisionModel.end(), '\n'), collisionModel.end());
	}	
}

const string Level::getModel() const
{
	string output;
	string::const_iterator it = model.begin();
	string::size_type colCount = 0;
	for (;it != model.end(); ++it, ++colCount)
	{
		
		output += *it;
		if (colCount == width)
		{
			output += '\n';
		}
	}
	return output;
}

const char Level::get(pos y, pos x) const
{
	if (y > height || x > width) return '\0';
	char output;
	string::const_iterator it = collisionModel.begin();
	return *(it + (y * width) + x);
}