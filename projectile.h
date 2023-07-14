#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"
class Projectile : public Satellite
{
public:
	Projectile(const Velocity& vel, const Position& pos, const Angle& ang);

	void draw(ogstream* gout);

private:
	int framesToLive;
};

