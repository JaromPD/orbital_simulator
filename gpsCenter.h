#pragma once
#include "part.h"
#include "position.h"
#include "velocity.h"
#include "fragment.h"
#include "angle.h"
class GPSCenter :
    public Part
{
public:

	GPSCenter(Position pos, Velocity velocity, Angle angle) : Part(pos, velocity, angle)
	{
		this->radius = 1;//7;
	};

    void draw(ogstream* gout) {
		gout->drawGPSCenter(pos, 0);
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

