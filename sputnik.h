#include "satellite.h"
#include "fragment.h"

class Sputnik : public Satellite
{
public:
	Sputnik() : Satellite()
	{
		this->pos = Position(-36515095.13, 21082000);
		this->velocity = Velocity(2050, 2684.68);
		radius = 4;
	}

	void draw(ogstream* gout)
	{
		gout->drawSputnik(pos, 0);
	}

	void destroy(list<Satellite*>* satellites)
	{
		bool addKick = true;

		float offset = (2 * M_PI) / 4;

		Fragment* fragment1 = new Fragment(pos, velocity, Angle(offset * 0), addKick);
		Fragment* fragment2 = new Fragment(pos, velocity, Angle(offset * 1), addKick);
		Fragment* fragment3 = new Fragment(pos, velocity, Angle(offset * 2), addKick);
		Fragment* fragment4 = new Fragment(pos, velocity, Angle(offset * 3), addKick);

		satellites->push_back(fragment1);
		satellites->push_back(fragment2);
		satellites->push_back(fragment3);
		satellites->push_back(fragment4);
	}

};