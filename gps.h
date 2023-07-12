#pragma once
#include "satellite.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"
#include "fragment.h"


class GPS : public Satellite
{
public:
<<<<<<< Updated upstream
	GPS(Position pos, Velocity vel) : Satellite()
	{
		this->pos = pos;
		this->velocity = vel;
		radius = 12;
	}
	void draw(ogstream* gout)
	{
		gout->drawGPS(pos, 0);
	}

	list<Part*> createDebris()
	{
		list<Part*> debris;

		Fragment* fragment1 = new Fragment(pos, velocity, angle);
		Fragment* fragment2 = new Fragment(pos, velocity, angle);
		GPSCenter* gpsCenter = new GPSCenter(pos, velocity, angle);
		GPSLeft* gpsLeft = new GPSLeft(pos, velocity, angle);
		GPSRight* gpsRight = new GPSRight(pos, velocity, angle);

		debris.push_back(fragment1);
		debris.push_back(fragment2);
		debris.push_back(gpsCenter);
		debris.push_back(gpsLeft);
		debris.push_back(gpsRight);

		return debris;
	}

	void destroy(list<Satellite*>* satellites)
	{
		list<Part*> debris = createDebris();
		float offset = (2 * M_PI) / debris.size();

		int partNum = 0;
		for (auto part : debris)
		{
			float angle = offset * (partNum);
			part->setAngleRadians(angle);

			part->addKick();
			part->move(3 * 48); // To Do: Make move take no parameters? Always assume the time == 48?
			satellites->push_back(part);
			partNum++;

		}
	}

=======
	GPS(Position pos, Velocity vel);
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
protected:
		list<Part*> getDebris();
>>>>>>> Stashed changes
};

