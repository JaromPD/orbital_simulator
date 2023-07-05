#pragma once
#include "part.h"
class GPSRight :
    public Part
{
    public:
	GPSRight(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick) {};
	void draw(ogstream* gout) {
		gout->drawGPSRight(pos, 0);
	};

private:
	float radius = 8;

};

