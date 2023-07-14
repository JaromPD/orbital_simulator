#include "fragment.h"
#include "uiDraw.h"

Fragment::Fragment(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick) : Part(pos, velocity, angle, addKick)
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