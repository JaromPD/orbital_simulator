#pragma once
class Angle
{
public:
	friend TestShip;

	Angle();
	Angle(float radians);

	void setRadians(float radians);
	void setDegrees(float degrees);
	void setDxDy(float dx, float dy);
	void setUp();
	void setDown();
	void setLeft();
	void setRight();
	void rotate(float radians);
	float getDegrees() const;
	float getRadians() const;
	float getDx() const;
	float getDy() const;
private:
	float radians;
};

