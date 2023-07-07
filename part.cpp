#include "part.h"
Part::Part(Position pos, Velocity velocity, Angle angle)
{
	this->velocity = velocity;
	this->angle = angle;
	this->pos = pos;
	this->angularVelocity = random(-100, 100); // To Do: Get this to add the spin.
}