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

class Hubble : public Satellite
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
};

class Dragon : public Satellite
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
};

class StarLink : public Satellite
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
};;