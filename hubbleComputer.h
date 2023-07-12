#pragma once
#include "part.h"
#include "fragment.h"
class HubbleComputer :
    public Part
{
public:
	HubbleComputer(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

