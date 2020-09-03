#include "Actor.h"

Actor::Actor(char model, pos y, pos x, int health, int strength, int speed) : Entity(model, y, x), health(health), strength(strength), speed(speed) { }
Actor::Actor(char model, pos y, pos x) : Actor(model, y, x, 10, 1, 0) { }
Actor::Actor(char model) : Actor(model, 1, 1) { }
Actor::Actor() : Actor(' ', -1, -1) { }