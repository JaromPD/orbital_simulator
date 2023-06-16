#pragma once
#include "whole.h"
#include "uiDraw.h"
class Ship :
    public Whole
{
public:
    Ship();
	Ship(Velocity vel, Position pos, Angle ang);
	void draw(ogstream* gout, bool thrust) const
	{
		gout->drawShip(pos, angle.getRadians(), thrust);
	}
	void destroy();
	void move();
	void input();
};

