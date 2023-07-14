#include "dragon.h"
Dragon::Dragon() : Satellite()
{
	this->pos = Position(0, 8000000);
	this->velocity = Velocity(-7900, 0);
	radius = 7;
}

void Dragon::draw(ogstream* gout)
{
	gout->drawCrewDragon(pos, getDirection().getRadians());
}

list<Part*> Dragon::getDebris()
{
	list<Part*> debris;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));
	DragonCenter* dragonCenter = new DragonCenter(pos, velocity, Angle(0));
	DragonLeft* dragonLeft = new DragonLeft(pos, velocity, Angle(0));
	DragonRight* dragonRight = new DragonRight(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(dragonCenter);
	debris.push_back(dragonLeft);
	debris.push_back(dragonRight);

	return debris;
}