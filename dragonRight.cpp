#include "dragonRight.h"
DragonRight::DragonRight(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 6;
};

void DragonRight::draw(ogstream* gout) {
	gout->drawCrewDragonRight(pos, this->angle.getRadians());
};

list<Part*> DragonRight::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}