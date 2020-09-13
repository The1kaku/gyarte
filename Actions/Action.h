#ifndef ActionHeader
#define ActionHeader

#include "Actor.h"

struct Action 
{
	void attack(Actor& attacker, Actor& defender);
};

#endif