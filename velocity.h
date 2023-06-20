#pragma once
#include "angle.h"

class TestShip;
class TestVelocity;

class Velocity
{
public:
	friend class TestShip; 
	friend class TestVelocity;

	Velocity() : dx(0), dy(0)
	{
		setDx(dx);
		setDy(dy);
	}
	Velocity(float dx, float dy);
	
	void assign(float velocity);
	float getDx() const { return dx; };
	float getDy() const { return dy; };
	float getSpeed() const;
	Angle getAngle() const;
	void setDx(float dx) { this->dx = dx; };
	void setDy(float dy) { this->dy = dy; };
	void setSpeed(float speed);
	void setAngle(Angle angle);
	void addDx(float dx) { this->dx += dx; };
	void addDy(float dy) { this->dy += dy; };
	void add(Velocity velocity);

private:
	float dx;
	float dy;
};

