#include "satellite.h"
#include "fragment.h"

class Sputnik : public Satellite
{
public:
	Sputnik();
	void draw(ogstream* gout);
	void destroy(list<Satellite*>* satellites);
};