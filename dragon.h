#pragma once
#include "satellite.h"
#include "fragment.h"
#include "dragonCenter.h"
#include "dragonLeft.h"
#include "dragonRight.h"

class Dragon : 
	public Satellite
{
public:
	Dragon();
	void draw(ogstream* gout);
protected:
	list<Part*> getDebris();
};

