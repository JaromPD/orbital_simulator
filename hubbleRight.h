#pragma once
#include "part.h"
#include "fragment.h"
class HubbleRight :
    public Part
{
public:
	HubbleRight(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

