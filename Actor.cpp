#include "Actor.h"

Actor::Actor(char model, pos y, pos x) : Entity(model, y, x) { }
Actor::Actor(char model) : Actor(model, 1, 1) { }
Actor::Actor() : Actor(' ', -1, -1) { }