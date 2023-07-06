#include "fragment.h"
#include "uiDraw.h"

Fragment::Fragment(Position pos, Velocity velocity, Angle angle, bool addKick)
{
	// To Do: This is reduntant code from part.cpp. The only dfference is the frames to live and draw.
	this->velocity = velocity;
	this->angle = angle;
	float newX = pos.getMetersX() + ( ( 4 * 128000) * cos(this->angle.getRadians()));
	float newY = pos.getMetersY() + ((4 * 128000) * sin(this->angle.getRadians()));
	this->pos = Position(newX, newY);
	this->angularVelocity = random(-100, 100);
	framesToLive = random(50, 100);

	if (addKick)
	{
		this->velocity.add(Velocity(random(5000, 9000), Angle(rand() % 360)));
	}
}