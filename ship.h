#pragma once
#include "whole.h"
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "projectile.h"

class Ship :
    public Whole
{
public:
	friend class TestShip;

	Ship() {}
	Ship(Velocity vel, Position pos, Angle ang, float angular);
	void draw(ogstream* gout, bool thrust)
	{
		gout->drawShip(pos, angle.getRadians(), thrust);
	}
	void destroy(list<Satellite*>& satellites);
	void move(float time);
	void input();

	void rotateLeft() {};
	void rotateRight() {};
	void setThrust(bool thrust) { this->thrust = thrust; };
	Projectile* fire() { Projectile* stubProj = new Projectile() ; return stubProj; };

private:
	bool thrust;
};

