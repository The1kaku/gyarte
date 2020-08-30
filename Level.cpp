#include "Level.h"

const string Level::getModel() const
{
	string output;
	string::const_iterator it = model.begin();
	string::size_type colCount = 1;
	for (;it != model.end(); ++it, ++colCount)
	{
		
		output += *it;
		if (colCount % width == 0)
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
	string::const_iterator it = model.begin();
	return *(it + (y * width) + x);
}