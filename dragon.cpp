#include "dragon.h"
Dragon::Dragon() : Satellite()
{
	this->pos = Position(0, 8000000);
	this->velocity = Velocity(-7900, 0);
	radius = 7;
}

void Dragon::draw(ogstream* gout)
{
	gout->drawCrewDragon(pos, 0);
}

list<Part*> Dragon::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);
	DragonCenter* dragonCenter = new DragonCenter(pos, velocity, Angle(0), addKick);
	DragonLeft* dragonLeft = new DragonLeft(pos, velocity, Angle(0), addKick);
	DragonRight* dragonRight = new DragonRight(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(dragonCenter);
	debris.push_back(dragonLeft);
	debris.push_back(dragonRight);

	return debris;
}