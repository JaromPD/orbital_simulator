#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"
class GPS : public Satellite
{
public:
	GPS(Position pos, Velocity vel);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

