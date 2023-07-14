#include "gpsLeft.h"
GPSLeft::GPSLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
{
	this->radius = 8;
};

void GPSLeft::draw(ogstream* gout) {
	gout->drawGPSLeft(pos, this->angle.getRadians());
};

list<Part*> GPSLeft::getDebris()
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