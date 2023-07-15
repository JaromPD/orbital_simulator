#include "part.h"
Part::Part(const Position& pos, const Velocity& velocity, const Angle& angle)
{
	this->velocity = velocity;
	this->angle = angle;
	this->pos = pos;
	this->angularVelocity = random(-.25, .25);
}

void Part::setRadians(float radians)
{
	this->angle.setRadians(radians);
}

void Part::kick(float kickAngle)
{
	this->velocity.add(Velocity(random(5000, 9000), Angle(kickAngle)));
	move();
	move();
	move();
	move();
	move();
}