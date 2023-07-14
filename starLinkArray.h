#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkArray :
    public Part
{
public:
	StarLinkArray(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

