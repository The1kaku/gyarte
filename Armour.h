#ifndef ARMOUR_H
#define ARMOUR_H

#include "Gear.h"

struct Armour : public Gear 
{
	Armour(std::string name, int rarity, std::string desc, int impact, int pierce, int slash) : Gear(name, rarity, desc), impact(impact), pierce(pierce), slash(slash) { } 
	Armour(int impact, int pierce, int slash) : Gear(), impact(impact), pierce(pierce), slash(slash) { } 
	Armour() : Armour(0, 0, 0) { }
	Armour(std::string name, int rarity, std::string desc) : Armour(name, rarity, desc, 0, 0, 0) { }
	
	int impact;
	int pierce;
	int slash;
};

#endif