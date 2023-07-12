#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"
class Projectile : public Satellite
{
public:
	Projectile(Velocity vel, Position pos, Angle ang);

	void draw(ogstream* gout);

private:
	int framesToLive;
};

