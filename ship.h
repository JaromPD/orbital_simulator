#pragma once
#include "whole.h"
#include "uiDraw.h"
#include "position.h"

class Ship :
    public Whole
{
public:
	friend class TestShip;

	Ship() {}
	Ship(Velocity vel, Position pos, Angle ang, float angular);
	void draw(ogstream* gout, bool thrust) const
	{
		gout->drawShip(pos, angle.getRadians(), thrust);
	}
	void destroy(list<Satellite*>& satellites);
	void move(float time);
	void input();

	void rotateLeft() {};
	void rotateRight() {};
	void setThrust(bool thrust) { this->thrust = thrust; };

private:
	bool thrust;
};

