#include "ship.h"
#include "fragment.h"

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

void Ship::destroy(list<Satellite*>& satellites)
{
	bool addKick = true;
	Fragment *fragment1 = new Fragment(velocity, angle, addKick);
	Fragment *fragment2 = new Fragment(velocity, angle, addKick);

	satellites.push_back(fragment1);
	satellites.push_back(fragment2);
}

void Ship::move(float time)
{
	float aGravity = getGravity(pos);
	updateVelocity(aGravity, time);
	updatePosition(time);
	angle.rotate(this->angularVelocity);
}

Projectile* Ship::fire()
{
	Velocity projVel = this->velocity;
	float newX = this->pos.getMetersX() + (760 * cos(this->angle.getRadians()));
	cout << "newX: " << newX << endl;
	float newY = this->pos.getMetersY() + (760 * sin(this->angle.getRadians()));
	cout << "newY: " << newY << endl;
	Position projPos(newX, newY);

	projVel.add(Velocity(9000, this->angle));

	Projectile *proj = new Projectile(projVel, projPos, this->angle);

	return proj;
}

void Ship::input()
{
	// Stub
}
