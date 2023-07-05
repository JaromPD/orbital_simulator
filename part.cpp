#include "part.h"
Part::Part(Position pos, Velocity velocity, Angle angle, bool addKick)
{
	this->velocity = velocity;
	this->angle = angle;
	float newX = pos.getMetersX() + (160 * cos(this->angle.getRadians()));
	float newY = pos.getMetersY() + (160 * sin(this->angle.getRadians()));
	this->pos = Position(newX, newY);
	this->angularVelocity = random(-100, 100); // To Do: Get this to add the spin.

	if (addKick)
	{
		this->velocity.add(Velocity(random(5000, 9000), Angle(rand() % 360)));
	}
}