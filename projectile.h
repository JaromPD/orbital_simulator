#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"
class Projectile : public Satellite
{
public:
	Projectile(Velocity vel, Position pos, Angle ang) : Satellite()
	{
		this->pos = pos;
		this->velocity = vel;
		this->angle = ang;
		radius = 1;
	}
	void draw(ogstream* gout)
	{
		gout->drawProjectile(pos);

		framesToLive--;
		if (framesToLive <= 0)
		{
			kill();
		}

	}

private:
	int framesToLive = 70;
};

