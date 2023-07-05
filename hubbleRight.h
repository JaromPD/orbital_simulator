#pragma once
#include "part.h"
#include "fragment.h"
class HubbleRight :
    public Part
{
public:

	HubbleRight(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) {};

	void draw(ogstream* gout) {
		gout->drawHubbleLeft(pos, 0);
	};

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle, addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, angle, addKick);


		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
	}

private:
	float radius = 8;
};

