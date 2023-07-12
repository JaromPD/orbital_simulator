#pragma once
#include "satellite.h"
#include "hubbleTelescope.h"
#include "hubbleComputer.h"
#include "hubbleLeft.h"
#include "hubbleRight.h"

class Hubble :
    public Satellite
{
public:
	Hubble() : Satellite()
	{
		this->pos = Position(0, -42164000);
		this->velocity = Velocity(3100, 0);
		radius = 10;
	}

	void draw(ogstream* gout)
	{
		gout->drawHubble(pos, 0);
	}

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;
		float offset = (2 * M_PI) / 4;

		HubbleTelescope* part1 = new HubbleTelescope(pos, velocity, Angle(offset * 0), addKick);
		HubbleComputer* part2 = new HubbleComputer(pos, velocity, Angle(offset * 1), addKick);
		HubbleLeft* part3 = new HubbleLeft(pos, velocity, Angle(offset * 2), addKick);
		HubbleRight* part4 = new HubbleRight(pos, velocity, Angle(offset * 3), addKick);


		satellites->push_back(part1);
		satellites->push_back(part2);
		satellites->push_back(part3);
		satellites->push_back(part4);

	}
};

