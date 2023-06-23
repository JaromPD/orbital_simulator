#include "Velocity.h"
#include <iostream>
using namespace std;

Velocity::Velocity(float vel, Angle ang)
{
	this->dx = vel * cos(ang.getRadians());
	this->dy = vel * sin(ang.getRadians());
}

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
	this->dx = this->dx + velocity.dx;
	this->dy = this->dy + velocity.dy;
}