#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkBody :
    public Part
{
public:
	StarLinkBody(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

