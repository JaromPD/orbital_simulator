#pragma once
#include "satellite.h"
class Fragment :
    public Satellite
{
public:
    Fragment() {};
    Fragment(Position pos, Velocity velocity, Angle angle);
    Fragment(Position pos, Velocity velocity, Angle angle, bool addKick);

    void draw(ogstream* gout) {
        gout->drawFragment(pos, 3);

        framesToLive--;
        if (framesToLive <= 0)
        {
            dead = true;
        };
    };

private:
    float radius = 2;
    int framesToLive = 1;
};

