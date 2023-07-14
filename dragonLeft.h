#pragma once
#include "part.h"
#include "fragment.h"
class DragonLeft :
    public Part
{
public:
	DragonLeft(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

