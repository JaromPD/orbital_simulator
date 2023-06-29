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
	virtual void destroy(list<Satellite*> &satellites); // Takes satellites as param
	virtual void move(float time);
	virtual void input();
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

class Sputnik : public Satellite
{
public:
	Sputnik() : Satellite()
	{
		this->pos = Position(-36515095.13, 21082000);
		this->velocity = Velocity(2050, 2684.68);
	}

	void draw(ogstream* gout)
	{
		gout->drawSputnik(pos, 0);
	}
};

class GPS : public Satellite
{
public:
	GPS(Position pos, Velocity vel) : Satellite()
	{
		this->pos = pos;
		this->velocity = vel;
	}
	void draw(ogstream* gout)
	{
		gout->drawGPS(pos, 0);
	}
};;

class Hubble : public Satellite
{
public:
	Hubble() : Satellite()
	{
		this->pos = Position(0, -42164000);
		this->velocity = Velocity(3100, 0);
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
	}
	void draw(ogstream* gout)
	{
		gout->drawStarlink(pos, 0);
	}
};;