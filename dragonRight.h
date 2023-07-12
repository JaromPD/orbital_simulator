#pragma once
#include "part.h"
#include "fragment.h"
class DragonRight :
    public Part
{
public:
	DragonRight(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

