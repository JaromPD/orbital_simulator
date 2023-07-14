#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkBody :
    public Part
{
public:
	StarLinkBody(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

