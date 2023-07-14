#pragma once
#include "part.h"
#include "fragment.h"
#include "position.h"
#include "velocity.h"
class DragonCenter :
    public Part
{
public:
	DragonCenter(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

