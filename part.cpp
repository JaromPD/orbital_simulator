#include "part.h"
Part::Part(const Position& pos, const Velocity& velocity, const Angle& angle)
{
	this->velocity = velocity;
	this->angle = angle;
	this->pos = pos;
	this->angularVelocity = random(-.25, .25); // To Do: Get this to add the spin.
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