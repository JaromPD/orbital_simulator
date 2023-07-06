#pragma once
#include "part.h"
class Fragment :
    public Part
{
public:
    Fragment() {};
    Fragment(Position pos, Velocity velocity, Angle angle, bool addKick) : Part(pos, velocity, angle, addKick)
	{
		// To Do: This is reduntant code from part.cpp. The only dfference is the frames to live and draw.
		this->angularVelocity = random(-100, 100);
		framesToLive = random(50, 100);
		radius = 2;

		if (addKick)
		{
			this->velocity.add(Velocity(random(5000, 9000), Angle(rand() % 360)));
		}

		move(2 * 48); // To Do: Make this use a constant
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

