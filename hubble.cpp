#include "hubble.h"

Hubble::Hubble() : Satellite()
{
	this->pos = Position(0, -42164000);
	this->velocity = Velocity(3100, 0);
	radius = 10;
}

void Hubble::draw(ogstream* gout)
{
	gout->drawHubble(pos, (getDirectionGravity().getRadians() / (-M_PI)));
}

list<Part*> Hubble::getDebris()
{
	list<Part*> debris;
	bool addKick = true;

	HubbleTelescope* part1 = new HubbleTelescope(pos, velocity, Angle(0));
	HubbleComputer* part2 = new HubbleComputer(pos, velocity, Angle(0));
	HubbleLeft* part3 = new HubbleLeft(pos, velocity, Angle(0));
	HubbleRight* part4 = new HubbleRight(pos, velocity, Angle(0));

	debris.push_back(part1);
	debris.push_back(part2);
	debris.push_back(part3);
	debris.push_back(part4);

	return debris;
}