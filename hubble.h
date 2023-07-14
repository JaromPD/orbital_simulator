#pragma once
#include "satellite.h"
#include "hubbleTelescope.h"
#include "hubbleComputer.h"
#include "hubbleLeft.h"
#include "hubbleRight.h"

class Hubble :
    public Satellite
{
public:
	Hubble();
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

