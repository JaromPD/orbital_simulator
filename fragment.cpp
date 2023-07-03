#include "fragment.h"
#include "uiDraw.h"

Fragment::Fragment(Position pos, Velocity velocity, Angle angle)
{
	this->pos = pos;
	this->velocity = velocity;
	this->angle = angle;
	angularVelocity = random(-100, 100);
	framesToLive = random(50, 100);
}

Fragment::Fragment(Position pos, Velocity velocity, Angle angle, bool addKick)
{
	this->pos = pos;
	this->velocity = velocity;
	this->angle = angle;
	this->angularVelocity = random(-100, 100);
	framesToLive = random(50, 100);


	if (addKick)
	{
		this->velocity.add(Velocity(random(5000, 9000), Angle(rand() % 360)));
	}
}