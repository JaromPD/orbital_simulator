#pragma once
#include "part.h"
#include "fragment.h"
class GPSRight :
    public Part
{
public:
	GPSRight(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

