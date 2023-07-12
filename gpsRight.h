#pragma once
#include "part.h"
#include "fragment.h"
class GPSRight :
    public Part
{
public:
	GPSRight(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

