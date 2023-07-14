#pragma once
#include "part.h"
#include "fragment.h"
class GPSLeft :
    public Part
{
public:
	GPSLeft(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

