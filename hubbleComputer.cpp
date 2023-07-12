#include "hubbleComputer.h"
HubbleComputer::HubbleComputer(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 7;
};

void HubbleComputer::draw(ogstream* gout) {
	gout->drawHubbleComputer(pos, 0);
};

void HubbleComputer::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 2;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
}