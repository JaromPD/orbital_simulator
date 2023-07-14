#include "dragonCenter.h"
DragonCenter::DragonCenter(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
{
	this->radius = 6;
};

void DragonCenter::draw(ogstream* gout) {
	gout->drawCrewDragonCenter(pos, this->angle.getRadians());
};

list<Part*> DragonCenter::getDebris()
{
	list<Part*> debris;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment3 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment4 = new Fragment(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(fragment3);
	debris.push_back(fragment4);

	return debris;
}