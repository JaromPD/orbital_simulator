#include "projectile.h"

Projectile::Projectile(Velocity vel, Position pos, Angle ang)
{
	this->velocity = vel;
	this->pos = pos;
	this->angle = ang;
}