#pragma once
#include "satellite.h"
class Part :
    public Satellite
{
public:
    Part() {};
    Part(Position pos, Velocity velocity, Angle angle, bool addKick);

    //virtual void draw(ogstream* gout) {};

private:
    float radius;
};

