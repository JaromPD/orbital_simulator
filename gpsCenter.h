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
	GPSCenter(const Position& pos, const Velocity& velocity, const Angle& angle);
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

