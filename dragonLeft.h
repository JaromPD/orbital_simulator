#pragma once
#include "part.h"
#include "fragment.h"
class DragonLeft :
    public Part
{
public:
	DragonLeft(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

