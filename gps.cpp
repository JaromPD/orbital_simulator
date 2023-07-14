#include "gps.h"
GPS::GPS(const Position& pos, const Velocity& vel) : Satellite()
{
	this->pos = pos;
	this->velocity = vel;
	radius = 12;
}
void GPS::draw(ogstream* gout)
{
	gout->drawGPS(pos, (getDirectionGravity().getRadians() + (M_PI / 2)));
}

list<Part*> GPS::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));
	GPSCenter* gpsCenter = new GPSCenter(pos, velocity, Angle(0));
	GPSLeft* gpsLeft = new GPSLeft(pos, velocity, Angle(0));
	GPSRight* gpsRight = new GPSRight(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(gpsCenter);
	debris.push_back(gpsLeft);
	debris.push_back(gpsRight);

	return debris;
}

