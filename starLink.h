#pragma once
#include "satellite.h"
#include "fragment.h"
#include "starLinkBody.h"
#include "starLinkArray.h"
class StarLink : 
	public Satellite
{
public:
	StarLink() : Satellite()
	{
		this->pos = Position(0, -13020000);
		this->velocity = Velocity(5800, 0);
		radius = 6;
	}
	void draw(ogstream* gout)
	{
		gout->drawStarlink(pos, 0);
	}

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle, addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, angle, addKick);
		StarLinkBody* body = new StarLinkBody(pos, velocity, angle, addKick);
		StarLinkArray* array = new StarLinkArray(pos, velocity, angle, addKick);

		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(body);
		satellites->push_back(array);
	}

};

