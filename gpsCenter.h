#pragma once
#include "part.h"
#include "position.h"
#include "velocity.h"
#include "fragment.h"
#include "angle.h"
class GPSCenter :
    public Part
{
public:
	GPSCenter(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

