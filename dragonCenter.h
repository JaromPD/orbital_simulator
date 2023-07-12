#pragma once
#include "part.h"
#include "fragment.h"
class DragonCenter :
    public Part
{
public:

	DragonCenter(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) 
	{
		this->radius = 6;
	};

	void draw(ogstream* gout) {
		gout->drawCrewDragonCenter(pos, 0);
	};

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;
		float offset = (2 * M_PI) / 4;

		Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);
		Fragment* fragment3 = new Fragment(pos, velocity, Angle(offset * 2), addKick);
		Fragment* fragment4 = new Fragment(pos, velocity, Angle(offset * 3), addKick);


		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(fragment3);
		satellites->push_back(fragment4);
	}
};

