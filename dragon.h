#pragma once
#include "satellite.h"
#include "fragment.h"
#include "dragonCenter.h"
#include "dragonLeft.h"
#include "dragonRight.h"

class Dragon : 
	public Satellite
{
public:
	Dragon() : Satellite()
	{
		this->pos = Position(0, 8000000);
		this->velocity = Velocity(-7900, 0);
		radius = 7;
	}

	void draw(ogstream* gout)
	{
		gout->drawCrewDragon(pos, 0);
	}

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		Fragment* fragment1 = new Fragment(pos, velocity, angle);
		Fragment* fragment2 = new Fragment(pos, velocity, angle);
		DragonCenter* dragonCenter = new DragonCenter(pos, velocity, angle);
		DragonLeft* dragonLeft = new DragonLeft(pos, velocity, angle);
		DragonRight* dragonRight = new DragonRight(pos, velocity, angle);


		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(dragonCenter);
		satellites->push_back(dragonLeft);
		satellites->push_back(dragonRight);
	}

};

