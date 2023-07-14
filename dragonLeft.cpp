#include "dragonLeft.h"
DragonLeft::DragonLeft(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
{
	this->radius = 6;
};

void DragonLeft::draw(ogstream* gout) {
	gout->drawCrewDragonLeft(pos, this->angle.getRadians());
};

list<Part*> DragonLeft::getDebris()
{
	list<Part*> debris;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);

	return debris;
}