#include "ship.h"
#include "fragment.h"
#include <math.h>
#define _USING_MATH_DEFINES

Ship::Ship(Velocity vel, Position pos, Angle ang, float angular)
{
	this->velocity = vel;
	this->pos = pos;
	this->angle = ang;
	this->angularVelocity = 0.00;
	this->angularVelocity = angular;
	this->dead = false;
	this->radius = 5.00;
	this->thrust = false;
}

void Ship::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, angle);
	Fragment* fragment2 = new Fragment(pos, velocity, angle);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
}

void Ship::move(float time)
{
	float aGravity = getGravity(pos);
	updateVelocity(aGravity, time);
	if (thrust)
	{
		Angle thrustAngle = angle.getRadians() - ((3 * M_PI )/ 2);
		velocity.add(Velocity(2*48, thrustAngle)); // To Do: Figure what speed really needs to be.
	}
	updatePosition(time);
	angle.rotate(this->angularVelocity);
}

Projectile* Ship::fire()
{
	Velocity projVel = this->velocity;
	Position projPos = this->pos;
	Angle projAngle = this->angle;
	projAngle.rotate(M_PI / 2);
	projVel.add(Velocity(9000, projAngle));

	Projectile* proj = new Projectile(projVel, projPos, projAngle);

	proj->move(2 * 48); // To Do: Use the time constant rather than hard code.

	return proj;
}

void Ship::input()
{
	// Stub
}
