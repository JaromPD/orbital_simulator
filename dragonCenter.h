#pragma once
#include "part.h"
#include "fragment.h"
#include "position.h"
#include "velocity.h"
class DragonCenter :
    public Part
{
public:
	DragonCenter(Position pos, Velocity velocity, Angle angle, bool addKick);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

