#pragma once
#include "part.h"
#include "fragment.h"
class GPSLeft :
    public Part
{
public:
	GPSLeft(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

