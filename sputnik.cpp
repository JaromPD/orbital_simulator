#include "sputnik.h"
#include "satellite.h"

Sputnik::Sputnik() : Satellite()
{
	this->pos = Position(-36515095.13, 21082000);
	this->velocity = Velocity(2050, 2684.68);
	radius = 4;
}

void Sputnik::draw(ogstream* gout)
{
	gout->drawSputnik(pos, 0);
}

list<Part*> Sputnik::getDebris()
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