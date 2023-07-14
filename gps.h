#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"
class GPS : public Satellite
{
public:
	GPS(const Position& pos, const Velocity& vel);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

