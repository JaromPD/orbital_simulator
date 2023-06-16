#pragma once
#include "velocity.h"
#include "position.h"
#include "angle.h"

class TestShip;

class Satellite
{
public:
	friend TestShip;

	Satellite();
	Satellite(Velocity vel, Position pos, Angle ang, int radius);

	float getRadius() const;
	bool isDead() const;
	Position getPosition() const;
	void kill();

	// Virtual functions
	virtual void draw();
	virtual void destroy(); // Takes satellites as param
	virtual void move();
	virtual void input();
protected:
	Velocity velocity;
	Position pos;
	Angle angle;
	float angularVelocity;
	bool dead;
	float radius;
};

