#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkArray :
    public Part
{
public:
	StarLinkArray(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

