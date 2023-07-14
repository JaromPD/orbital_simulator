#include "starLinkBody.h"
StarLinkBody::StarLinkBody(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick) : Part(pos, velocity, angle, addKick)
{
	this->radius = 2;
};

void StarLinkBody::draw(ogstream* gout) {
	gout->drawStarlinkBody(pos, 0);
};

void StarLinkBody::destroy(list<Satellite*>* satellites)
{
	bool addKick = true;
	float offset = (2 * M_PI) / 3;

	Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
	Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);
	Fragment* fragment3 = new Fragment(pos, velocity, Angle(offset * 2), addKick);

	satellites->push_back(fragment1);
	satellites->push_back(fragment2);
	satellites->push_back(fragment3);
}