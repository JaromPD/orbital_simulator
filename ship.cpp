#include "ship.h"

Ship::Ship(Velocity vel, Position pos, Angle ang, float angular)
{
	this->velocity = vel;
	this->pos = pos;
	this->angle = ang;
	this->angularVelocity = angular;
}

void Ship::destroy(list<Satellite*>& satellites)
{
	// Stub
}

void Ship::move(float time)
{
	// Stub
}

void Ship::input()
{
	// Stub
}
