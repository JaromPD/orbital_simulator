#pragma once
#include "part.h"
class Fragment :
    public Part
{
public:
    Fragment() {};
    Fragment(Position pos, Velocity velocity, Angle angle) : Part(pos, velocity, angle)
	{
		// To Do: This is reduntant code from part.cpp. The only dfference is the frames to live and draw.
		this->angularVelocity = random(-100, 100);
		framesToLive = random(50, 100);
		radius = 2;
	}

	void draw(ogstream* gout) {
		gout->drawFragment(pos, 0);
		framesToLive--;
		if (framesToLive <= 0)
		{
			kill();
		}
	};

private:
    int framesToLive;
};

