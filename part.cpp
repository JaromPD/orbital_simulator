#include "part.h"
Part::Part(Position pos, Velocity velocity, Angle angle, bool addKick)
{
	this->velocity = velocity;
	this->angle = angle;
	this->pos = pos;
	this->angularVelocity = random(-100, 100); // To Do: Get this to add the spin.

	if (addKick)
	{
		this->velocity.add(Velocity(random(5000, 9000), Angle(rand() % 360)));
	}

	move(3*48); // To Do: Make this use a constant/
}