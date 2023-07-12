#include "star.h"
Star::Star() {
	phase = random(0, 255);

	int posx = random(-1000, 1000);
	int posy = random(-1000, 1000);

	ptStar.setPixelsX(posx);
	ptStar.setPixelsY(posy);
};

void Star::draw(ogstream* gout) {

	gout->drawStar(ptStar, phase++);

};