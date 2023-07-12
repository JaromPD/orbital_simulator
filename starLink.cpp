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

void StarLink::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 5;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);
	StarLinkBody* body = new StarLinkBody(pos, velocity, Angle(offset * 2), addKick);
	StarLinkArray* array = new StarLinkArray(pos, velocity, Angle(offset * 3), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
	satellites->push_back(body);
	satellites->push_back(array);
}