#pragma once
#include "part.h"
#include "fragment.h"
class HubbleRight :
    public Part
{
public:
	HubbleRight(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

