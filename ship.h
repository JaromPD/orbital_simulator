#pragma once
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "projectile.h"

class Ship :
    public Satellite
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
	Ship(const Velocity& vel, const Position& pos, const Angle& ang, float angular);
	void draw(ogstream* gout)
	{
		gout->drawShip(pos, angle.getRadians(), thrust);
	}
	void move();

	void rotateLeft() { angle.setRadians(angle.getRadians() - 0.1); };
	void rotateRight() { angle.setRadians(angle.getRadians() + 0.1); };
	void setThrust(bool thrust) { this->thrust = thrust; };
	Projectile* fire();

private:
	bool thrust;
	list<Part*> getDebris();
};

