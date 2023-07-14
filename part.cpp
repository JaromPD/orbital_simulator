#include "part.h"
Part::Part(Position pos, Velocity velocity, Angle angle, bool addKick) // To Do: It's gonna suck but the addKick has got to go. It has no use anymore.
{
	this->velocity = velocity;
	this->angle = angle;
	this->pos = pos;
	this->angularVelocity = random(-.5, .5); // To Do: Get this to add the spin.
}

void Part::setRadians(float radians)
{
	this->angle.setRadians(radians);
}

void Part::kick(float kickAngle)
{
	this->velocity.add(Velocity(random(5000, 9000), Angle(kickAngle)));
	move(5 * 48); // To Do: Make this use a constant.
}