#include "gpsCenter.h"
GPSCenter::GPSCenter(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 7;
};

void GPSCenter::draw(ogstream* gout) {
	gout->drawGPSCenter(pos, 0);
};

void GPSCenter::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 3;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);
	Fragment* fragment3 = new Fragment(pos, velocity, Angle(offset * 2), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
	satellites->push_back(fragment3);
}