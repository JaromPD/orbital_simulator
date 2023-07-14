#pragma once
#include "part.h"
#include "fragment.h"
class StarLinkArray :
    public Part
{
public:
	StarLinkArray(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

