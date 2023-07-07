#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkArray :
    public Part
{
public:

	StarLinkArray(Position pos, Velocity velocity, Angle angle)
	{
		this->radius = 4;
	};

	void draw(ogstream* gout) {
		gout->drawStarlinkArray(pos, 0);
	};

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle);
		Fragment* fragment2 = new Fragment(pos, velocity, angle);
		Fragment* fragment3 = new Fragment(pos, velocity, angle);

		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(fragment3);
	}
};

