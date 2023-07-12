#include "projectile.h"
Projectile::Projectile(Velocity vel, Position pos, Angle ang) : Satellite()
{
	this->pos = pos;
	this->velocity = vel;
	this->angle = ang;
	framesToLive = 70;
	radius = 1;
}

void Projectile::draw(ogstream* gout)
{
	gout->drawProjectile(pos);

	framesToLive--;
	if (framesToLive <= 0)
	{
		kill();
	}

}