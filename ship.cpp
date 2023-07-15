#include "ship.h"
#include "fragment.h"
#include <math.h>
#define _USING_MATH_DEFINES
#define SECONDS_PER_FRAME 48

Ship::Ship(const Velocity& vel, const Position& pos, const Angle& ang, float angular)
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

list<Part*> Ship::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}

void Ship::move()
{
	float aGravity = getGravity(pos);
	updateVelocity(aGravity, SECONDS_PER_FRAME);
	if (thrust)
	{
		Angle thrustAngle = angle.getRadians() - ((3 * M_PI )/ 2);
		velocity.add(Velocity(2*SECONDS_PER_FRAME, thrustAngle));
	}
	updatePosition(SECONDS_PER_FRAME);
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

	proj->move();
	proj->move();

	return proj;
}
