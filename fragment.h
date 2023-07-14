#pragma once
#include "part.h"
class Fragment :
    public Part
{
public:
    Fragment() {};
	Fragment(const Position& pos, const Velocity& velocity, const Angle& angle, bool addKick);

    void draw(ogstream* gout);

private:
    int framesToLive;
};

