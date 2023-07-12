#pragma once
#include "satellite.h"
#include "fragment.h"
#include "starLinkBody.h"
#include "starLinkArray.h"
class StarLink : 
	public Satellite
{
public:
	StarLink();
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};

