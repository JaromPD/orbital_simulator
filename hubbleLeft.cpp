#include "hubbleLeft.h"
HubbleLeft::HubbleLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
{
	this->radius = 8;
};

void HubbleLeft::draw(ogstream* gout) {
	gout->drawHubbleLeft(pos, this->angle.getRadians());
};

list<Part*> HubbleLeft::getDebris()
{
	list<Part*> debris;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}