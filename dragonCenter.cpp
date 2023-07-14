#include "dragonCenter.h"
DragonCenter::DragonCenter(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 6;
};

void DragonCenter::draw(ogstream* gout) {
	gout->drawCrewDragonCenter(pos, this->angle.getRadians());
};

list<Part*> DragonCenter::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment3 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment4 = new Fragment(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(fragment3);
	debris.push_back(fragment4);

	return debris;
}