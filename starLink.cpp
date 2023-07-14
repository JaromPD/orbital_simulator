#include "starLink.h"
StarLink::StarLink() : Satellite()
{
	this->pos = Position(0, -13020000);
	this->velocity = Velocity(5800, 0);
	radius = 6;
}
void StarLink::draw(ogstream* gout)
{
	gout->drawStarlink(pos, 0);
}

list<Part*> StarLink::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0), addKick);
	StarLinkBody* body = new StarLinkBody(pos, velocity, Angle(0), addKick);
	StarLinkArray* array = new StarLinkArray(pos, velocity, Angle(0), addKick);

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(body);
	debris.push_back(array);

	return debris;
}