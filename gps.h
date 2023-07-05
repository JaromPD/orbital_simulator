#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"
class GPS : public Satellite
{
public:
	GPS(Position pos, Velocity vel) : Satellite()
	{
		this->pos = pos;
		this->velocity = vel;
		radius = 12;
	}
	void draw(ogstream* gout)
	{
		gout->drawGPS(pos, 0);
	}

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle, addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, angle, addKick);
		GPSCenter* gpsCenter = new GPSCenter(pos, velocity, angle, addKick);
		GPSLeft* gpsLeft = new GPSLeft(pos, velocity, angle, addKick);
		GPSRight* gpsRight = new GPSRight(pos, velocity, angle, addKick);

		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(gpsCenter);
		satellites->push_back(gpsLeft);
		satellites->push_back(gpsRight);
	}

};

