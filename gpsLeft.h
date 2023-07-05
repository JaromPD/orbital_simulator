#pragma once
#include "part.h"
class GPSLeft :
    public Part
{
    public:
	GPSLeft(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) {};
	void draw(ogstream* gout) {
		gout->drawGPSLeft(pos, 0);
	};

private:
	float radius = 8;
};

