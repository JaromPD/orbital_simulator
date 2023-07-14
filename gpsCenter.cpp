#include "gpsCenter.h"
GPSCenter::GPSCenter(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
{
	this->radius = 7;
};

void GPSCenter::draw(ogstream* gout) {
	gout->drawGPSCenter(pos, this->angle.getRadians());
};

list<Part*> GPSCenter::getDebris()
{
	list<Part*> debris;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment3 = new Fragment(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(fragment3);

	return debris;
}