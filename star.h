#pragma once
#include "position.h"
#include "uiDraw.h"

class Star
{
public:
	Star();
	void draw(ogstream* gout);
private:
	Position ptStar;
	unsigned char phase;
};

