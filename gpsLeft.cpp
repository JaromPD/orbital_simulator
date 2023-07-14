#include "gpsLeft.h"
GPSLeft::GPSLeft(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 8;
};

void GPSLeft::draw(ogstream* gout) {
	gout->drawGPSLeft(pos, this->angle.getRadians());
};

list<Part*> GPSLeft::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment3 = new Fragment(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(fragment3);

	return debris;
}