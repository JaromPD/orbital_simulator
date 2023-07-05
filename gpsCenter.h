#pragma once
#include "part.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
class GPSCenter :
    public Part
{
public:

	GPSCenter(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) {};

    void draw(ogstream* gout) {
		gout->drawGPSCenter(pos, 0);
	};

private:
	float radius = 7;
};

