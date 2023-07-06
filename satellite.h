#pragma once
#define _USE_MATH_DEFINES
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include <math.h>
#include <cmath>
#include <list>
using namespace std;

class TestShip;

class Satellite
{
public:
	friend class TestShip;

	Satellite() : angularVelocity(0), dead(false), radius(0)
	{
		// Stub
	}

	float getRadius()      const { return radius; };
	bool isDead()          const { return dead;   };
	Position getPosition() const { return pos;    };
	void kill();

	// Virtual functions
	virtual void draw(ogstream* gout) {};
	virtual void destroy(list<Satellite*>* satellites); // Takes satellites as param
	void move(float time);
	virtual void input();
	bool isColliding(Satellite* other);
	bool isCollidingEarth();
protected:
	float getGravity(Position pos);
	void updateVelocity(float aGravity, float time);
	void updatePosition(float time);

	Velocity velocity;
	Position pos;
	Angle angle;
	float angularVelocity;
	bool dead;
	float radius;
};
