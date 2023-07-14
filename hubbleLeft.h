#pragma once
#include "part.h"
#include "fragment.h"
class HubbleLeft :
    public Part
{
public:
	HubbleLeft(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

