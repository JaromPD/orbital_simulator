#include "Velocity.h"

Velocity::Velocity(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

void Velocity::assign(float velocity)
{
	// Stub
}

float Velocity::getSpeed() const
{
	return 0.0; // Stub
}

Angle Velocity::getAngle() const
{
	return Angle(0.0); // Stub
}

void Velocity::setSpeed(float speed)
{
	// Stub
}

void Velocity::setAngle(Angle angle)
{
	// Stub
}

void Velocity::add(Velocity velocity)
{
	// Stub
}