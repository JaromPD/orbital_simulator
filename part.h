#pragma once
#include "satellite.h"
class Part :
    public Satellite
{
public:
    Part() {};
    Part(Position pos, Velocity velocity, Angle angle);
    void addKick() { this->velocity.add(Velocity(random(5000, 9000), angle)); };
};

