#include "gps.h"
GPS::GPS(const Position& pos, const Velocity& vel) : Satellite()
{
	this->pos = pos;
	this->velocity = vel;
	radius = 12;
}
void GPS::draw(ogstream* gout)
{
	gout->drawGPS(pos, 0);
}

list<Part*> GPS::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);
	GPSCenter* gpsCenter = new GPSCenter(pos, velocity, Angle(0), addKick);
	GPSLeft* gpsLeft = new GPSLeft(pos, velocity, Angle(0), addKick);
	GPSRight* gpsRight = new GPSRight(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(gpsCenter);
	debris.push_back(gpsLeft);
	debris.push_back(gpsRight);

	return debris;
}

