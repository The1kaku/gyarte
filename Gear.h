#ifndef GEAR_H
#define GEAR_H

#include <string>

struct Gear 
{
	Gear(std::string name, int rarity, std::string description) : name(name), rarity(rarity), description(description) { }
	Gear() : Gear("", 0, "") { }
	std::string name;
	int rarity;
	std::string description;
	
	const char *getDesc() { return description.c_str(); }
	const char *getName() { return name.c_str(); }
};

#endif