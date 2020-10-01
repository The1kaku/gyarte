#ifndef WEAPON_H
#define WEAPON_H

#include "Gear.h"

struct Weapon : public Gear
{
	Weapon(std::string name, int rarity, std::string desc, int impact, int pierce, int slash) : Gear(name, rarity, desc), impact(impact), pierce(pierce), slash(slash) { } 
	Weapon(int impact, int pierce, int slash) : Gear(), impact(impact), pierce(pierce), slash(slash) { } 
	Weapon() : Weapon(0, 0, 0) { }
	Weapon(std::string name, int rarity, std::string desc) : Weapon(name, rarity, desc, 0, 0, 0) { }	
	
	int impact;
	int pierce;
	int slash;
};

#endif