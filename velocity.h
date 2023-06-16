#pragma once
class TestShip;

class Velocity
{
public:
	friend TestShip;

	Velocity();
	Velocity(float dx, float dy);
	
	void assign(float velocity);
	float getDx() const;
	float getDy() const;
	float getSpeed() const;
	Angle getAngle() const;
	void setDx(float dx);
	void setDy(float dy);
	void setSpeed(float speed);
	void setAngle(Angle angle);
	void addDx(float dx);
	void addDy(float dy);
	void add(Velocity velocity);
private:
	float dx;
	float dy;
};

