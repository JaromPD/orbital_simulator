#pragma once
#include "part.h"
#include "fragment.h"
class GPSRight :
    public Part
{
    public:
	GPSRight(Position pos, Velocity velocity, Angle angle) : Part(pos, velocity, angle) 
	{
		this->radius = 1;// 8;
	};

	void draw(ogstream* gout) {
		gout->drawGPSRight(pos, 0);
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

