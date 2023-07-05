#pragma once
#include "part.h"
class Fragment :
    public Part
{
public:
    Fragment() {};
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
    int framesToLive = 70;
};

