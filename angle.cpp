#include "angle.h"
#include <iostream>
using namespace std;

void Angle::normalizeRadians()
{
	if (this->radians > 2 * M_PI)
	{
		this->radians -= 2 * M_PI;
	}
	else if (this->radians < 0)
	{
		this->radians += 2 * M_PI;
	}
}

float Angle::convertRadiansToDegrees() const
{
	return(this->radians * (180 / M_PI));
}

void Angle::setRadians(float radians)
{ 
	this->radians = radians;
	normalizeRadians();
}

void Angle::setDegrees(float degrees)
{
	this->radians = degrees * (M_PI / 180);
	normalizeRadians();
}

void Angle::setDxDy(float dx, float dy)
{
	this->radians = atan2(dy, dx);
	normalizeRadians();
}

float Angle::getDegrees() const
{
	return(convertRadiansToDegrees());
}

float Angle::getRadians() const
{
	return(this->radians);
}

void Angle::rotate(float radians)
{
	this->radians += radians;
	normalizeRadians();
}

