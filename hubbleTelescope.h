#pragma once
#include "part.h"
#include "fragment.h"
class HubbleTelescope :
    public Part
{
public:
	HubbleTelescope(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

