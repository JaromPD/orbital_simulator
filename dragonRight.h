#pragma once
#include "part.h"
#include "fragment.h"
class DragonRight :
    public Part
{
public:
	DragonRight(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

