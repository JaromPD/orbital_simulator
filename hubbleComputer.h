#pragma once
#include "part.h"
#include "fragment.h"
class HubbleComputer :
    public Part
{
public:
	HubbleComputer(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

