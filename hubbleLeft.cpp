#include "hubbleLeft.h"
HubbleLeft::HubbleLeft(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 8;
};

void HubbleLeft::draw(ogstream* gout) {
	gout->drawHubbleLeft(pos, this->angle.getRadians());
};

list<Part*> HubbleLeft::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}