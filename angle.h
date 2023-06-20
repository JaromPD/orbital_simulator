#pragma once
class TestShip;
class Test;

class Angle
{
public:
	friend class TestShip;
	friend class TestAngle;

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
	float getDegrees() const { return 0.00; };
	float getRadians() const { return radians; };
	float getDx() const { return 0.00; };
	float getDy() const { return 0.00; };
private:
	float radians;
};

