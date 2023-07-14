#pragma once
#include "satellite.h"
class Part :
    public Satellite
{
public:
    Part() {};
    Part(const Position& pos, const Velocity& velocity, const Angle& angle);
    void setRadians(float radians);
    void kick(float kickAngle);
};

