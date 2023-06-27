#pragma once
#include "position.h"
#include "uiDraw.h"

class Star
{
public:
	Star() {
		phase = random(0, 255);

		int posx = random(-1000, 1000);
		int posy = random(-1000, 1000);

		ptStar.setPixelsX(posx);
		ptStar.setPixelsY(posy);
	};

	void draw(ogstream* gout) {
	
		gout->drawStar(ptStar, phase++);

	};

private:
	Position ptStar;
	unsigned char phase;
};

