#include "fragment.h"
#include "uiDraw.h"

Fragment::Fragment(const Position& pos, const Velocity& velocity, const Angle& angle) : Part(pos, velocity, angle)
{
	framesToLive = random(50, 100);
}

void Fragment::draw(ogstream* gout) 
{
	gout->drawFragment(pos, this->angle.getRadians());
	framesToLive--;
	if (framesToLive <= 0)
	{
		kill();
	}
};