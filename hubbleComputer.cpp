#include "hubbleComputer.h"
HubbleComputer::HubbleComputer(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 7;
};

void HubbleComputer::draw(ogstream* gout) {
	gout->drawHubbleComputer(pos, this->angle.getRadians());
};

list<Part*> HubbleComputer::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}