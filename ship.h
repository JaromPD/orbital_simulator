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

	Ship() 
	{
		this->velocity = Velocity();
		this->pos = Position(21082000, 36515095.125);
		this->angle = Angle();
		this->angularVelocity = 0.00;
		this->dead = false;
		this->radius = 5.00;
		this->thrust = false;
	};
	Ship(Velocity vel, Position pos, Angle ang, float angular);
	void draw(ogstream* gout)
	{
		cout << pos.getMetersX() << endl;
		cout << pos.getMetersY() << endl;
		gout->drawShip(pos, angle.getRadians(), thrust);
	}
	void destroy(list<Satellite*>& satellites);
	void move(float time);
	void input();

	void rotateLeft() {};
	void rotateRight() {};
	void setThrust(bool thrust) { this->thrust = thrust; };
	Projectile* fire();

private:
	bool thrust;
};

