#include "satellite.h"
#include <cmath>
#define EARTH_RADIUS 6378000
#define EARTH_GRAVITY -9.80665
using namespace std;

void Satellite::kill()
{
	dead = true;
}

void Satellite::destroy(list<Satellite*>* satellites)
{

}

float Satellite::getGravity(Position pos)
{
	// First get the height from earth.
	float height = sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - EARTH_RADIUS;
	// Then calculate the gravity at that height.
	float gravity = EARTH_GRAVITY * ((EARTH_RADIUS / (EARTH_RADIUS + height)) * (EARTH_RADIUS / (EARTH_RADIUS + height)));
	return gravity;
}

void Satellite::updateVelocity(float aGravity, float time)
{
	float newDx;
	float newDy;

	float gravityDirection = atan2(pos.getMetersX(), pos.getMetersY());

	float ddx = aGravity * sin(gravityDirection);
	float ddy = aGravity * cos(gravityDirection);

	newDx = velocity.getDx() + (ddx * time);
	newDy = velocity.getDy() + (ddy * time);

	velocity.setDx(newDx);
	velocity.setDy(newDy);
}

void Satellite::updatePosition(float time)
{
	float newX;
	float newY;
	newX = pos.getMetersX() + (velocity.getDx() * time);
	newY = pos.getMetersY() + (velocity.getDy() * time);
	pos.setMetersX(newX);
	pos.setMetersY(newY);
}

void Satellite::move(float time)
{
	float aGravity = getGravity(pos);
	updateVelocity(aGravity, time);
	updatePosition(time);
	angle.rotate(this->angularVelocity);
}

void Satellite::input()
{
	// Stub
}

bool Satellite::isColliding(Satellite* other)
{

	float distance = sqrt((pos.getMetersX() - other->pos.getMetersX()) * (pos.getMetersX() - other->pos.getMetersX()) + 
		                  (pos.getMetersY() - other->pos.getMetersY()) * (pos.getMetersY() - other->pos.getMetersY()));

	float radii = (radius + other->radius) * 128000; // Since the zoom is 128000, we need to multiply by that to get the correct radius. To Do: Make this scale with zoom.

	if (distance < radii)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Satellite::isCollidingEarth()
{
	float distance = sqrt((pos.getMetersX() - 0) * (pos.getMetersX() - 0) + 
		                  (pos.getMetersY() - 0) * (pos.getMetersY() - 0));

	float radii = (radius + 128000) + EARTH_RADIUS; // Since the zoom is 128000, we need to multiply by that to get the correct radius. To Do: Make this scale with zoom.
	if (distance < radii)
	{
		return true;
	}
	else
	{
		return false;
	}
}
