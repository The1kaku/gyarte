#include "Action.h"

void Action::attack(Actor& attacker, Actor& defender)
{
	defender.health -= attacker.strength; 
}