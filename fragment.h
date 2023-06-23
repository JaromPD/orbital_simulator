#pragma once
#include "satellite.h"
class Fragment :
    public Satellite
{
public:
    Fragment() {};
    Fragment(Velocity velocity, Angle angle) {};
    Fragment(Velocity velocity, Angle angle, bool addKick) {};
private:
    float radius = 2;
};

