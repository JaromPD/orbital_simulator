#pragma once
class TestShip;

class Angle
{
public:
	friend TestShip;

	Angle() : radians(0.00) {};
	Angle(float radians);

	void setRadians(float radians);
	void setDegrees(float degrees);
	void setDxDy(float dx, float dy);
	void setUp() {};
	void setDown() {};
	void setLeft() {};
	void setRight() {};
	void rotate(float radians) {};
	float getDegrees() const {};
	float getRadians() const { return radians; };
	float getDx() const {};
	float getDy() const {};
private:
	float radians;
};

