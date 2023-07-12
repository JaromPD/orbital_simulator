#include "gps.h"
GPS::GPS(Position pos, Velocity vel) : Satellite()
{
	this->pos = pos;
	this->velocity = vel;
	radius = 12;
}
void GPS::draw(ogstream* gout)
{
	gout->drawGPS(pos, 0);
}

void GPS::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 5;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset), addKick);
	GPSCenter* gpsCenter = new GPSCenter(pos, velocity, Angle(offset * 2), addKick);
	GPSLeft* gpsLeft = new GPSLeft(pos, velocity, Angle(offset * 3), addKick);
	GPSRight* gpsRight = new GPSRight(pos, velocity, Angle(offset * 4), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
	satellites->push_back(gpsCenter);
	satellites->push_back(gpsLeft);
	satellites->push_back(gpsRight);
}