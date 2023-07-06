#pragma once
#include "part.h"
#include "fragment.h"
class DragonRight :
    public Part
{
public:

	DragonRight(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
	{
		this->radius = 6;
	};

	void draw(ogstream* gout) {
		gout->drawCrewDragonRight(pos, 0);
	};

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle, addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, angle, addKick);


		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
	}
};

