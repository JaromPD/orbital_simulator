#pragma once
#include "satellite.h"
class Part :
    public Satellite
{
public:
    Part() {};
    Part(Position pos, Velocity velocity, Angle angle, bool addKick);
    void setRadians(float radians);
};

