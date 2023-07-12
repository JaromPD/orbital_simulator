#pragma once
#define _USE_MATH_DEFINES
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "part.h"
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

	Satellite(Velocity vel, Position pos, Angle angle)
	{
		this->velocity = vel;
		this->pos = pos;
		this->angle = angle;
	}

	float getRadius()      const { return radius; };
	bool isDead()          const { return dead;   };
	Position getPosition() const { return pos;    };
	void kill();
	void setAngleRadians(float angle) { this->angle.setRadians(angle); }; // To Do: Do we want other classes to be able to set the angle? Part will need to to space themselves out evenly.

	// Virtual functions
	virtual void draw(ogstream* gout) {};
	void destroy(list<Satellite*>* satellites); // Takes satellites as param
	void move(float time);
	virtual void input();
	bool isColliding(Satellite* other);
	bool isCollidingEarth();
protected:
	float getGravity(Position pos);
	void updateVelocity(float aGravity, float time);
	void updatePosition(float time);
	virtual list<Part*>* getDebris();

	Velocity velocity;
	Position pos;
	Angle angle;
	float angularVelocity;
	bool dead;
	float radius;
};
