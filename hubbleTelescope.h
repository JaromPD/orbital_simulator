#pragma once
#include "part.h"
#include "fragment.h"
class HubbleTelescope :
    public Part
{
public:
	HubbleTelescope(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

