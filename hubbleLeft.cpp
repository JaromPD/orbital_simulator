#include "hubbleLeft.h"
HubbleLeft::HubbleLeft(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 8;
};

void HubbleLeft::draw(ogstream* gout) {
	gout->drawHubbleLeft(pos, 0);
};

void HubbleLeft::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 2;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
}