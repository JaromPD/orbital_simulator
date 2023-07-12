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

void Dragon::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 5;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);
	DragonCenter* dragonCenter = new DragonCenter(pos, velocity, Angle(offset * 2), addKick);
	DragonLeft* dragonLeft = new DragonLeft(pos, velocity, Angle(offset * 3), addKick);
	DragonRight* dragonRight = new DragonRight(pos, velocity, Angle(offset * 4), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
	satellites->push_back(dragonCenter);
	satellites->push_back(dragonLeft);
	satellites->push_back(dragonRight);
}