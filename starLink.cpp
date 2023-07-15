#include "starLink.h"
StarLink::StarLink() : Satellite()
{
	this->pos = Position(0, -13020000);
	this->velocity = Velocity(5800, 0);
	radius = 6;
}
void StarLink::draw(ogstream* gout)
{
	gout->drawStarlink(pos, getDirection().getRadians());
}

list<Part*> StarLink::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(0));
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(0));
	StarLinkBody* body = new StarLinkBody(pos, velocity, Angle(0));
	StarLinkArray* array = new StarLinkArray(pos, velocity, Angle(0));

	debris.push_back(fragment1);
	debris.push_back(fragment2);
	debris.push_back(body);
	debris.push_back(array);

	return debris;
}