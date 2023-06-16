#pragma once
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include <list>
using namespace std;

class TestShip;

class Satellite
{
public:
	friend TestShip;

	Satellite() : angularVelocity(0), dead(false), radius(0)
	{
		// Stub
	}

	float getRadius()      const { return radius; };
	bool isDead()          const { return dead;   };
	Position getPosition() const { return pos;    };
	void kill();

	// Virtual functions
	virtual void draw();
	virtual void destroy(list<Satellite*> &satellites); // Takes satellites as param
	virtual void move(float time);
	virtual void input();
protected:
	Velocity velocity;
	Position pos;
	Angle angle;
	float angularVelocity;
	bool dead;
	float radius;
};

