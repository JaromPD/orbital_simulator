#pragma once
#include "part.h"
class Fragment :
    public Part
{
public:
    Fragment() {};
	Fragment(Position pos, Velocity velocity, Angle angle, bool addKick);

    void draw(ogstream* gout);

private:
    int framesToLive;
};

