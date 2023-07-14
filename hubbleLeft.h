#pragma once
#include "part.h"
#include "fragment.h"
class HubbleLeft :
    public Part
{
public:
	HubbleLeft(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

