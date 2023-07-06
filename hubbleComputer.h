#pragma once
#include "part.h"
#include "fragment.h"
class HubbleComputer :
    public Part
{
public:

	HubbleComputer(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) 
	{
		this->radius = 7;
	};

	void draw(ogstream* gout) {
		gout->drawHubbleComputer(pos, 0);
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

