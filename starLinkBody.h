#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkBody :
    public Part
{
public:

	StarLinkBody(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) {};

	void draw(ogstream* gout) {
		gout->drawStarlinkBody(pos, 0);
	};

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle, addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, angle, addKick);
		Fragment* fragment3 = new Fragment(pos, velocity, angle, addKick);

		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(fragment3);
	}

private:
	float radius = 2;
};
