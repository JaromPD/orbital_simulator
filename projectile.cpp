#include "projectile.h"

Projectile::Projectile(Velocity vel, Position pos, Angle ang)
{
	this->velocity = vel;
	this->pos = pos;
	this->angle = ang;
}

void Projectile::draw(ogstream* gout)
{
	gout->drawProjectile(pos); 

	framesToLive--; 

	if (framesToLive == 0) 
	{ 
		dead = true; 
	};
}