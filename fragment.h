#pragma once
#include "satellite.h"
class Fragment :
    public Satellite
{
public:
    Fragment() {};
    Fragment(Velocity velocity, Angle angle) {};
    Fragment(Velocity velocity, Angle angle, bool addKick) {};

    void draw(ogstream* gout) {
        gout->drawFragment(pos, 0);
    };

private:
    float radius = 2;
};

