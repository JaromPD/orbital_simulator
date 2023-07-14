#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkBody :
    public Part
{
public:
	StarLinkBody(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

