#pragma once
#include "satellite.h"
#include "velocity.h"
#include "position.h"
#include "angle.h"

class Projectile :
    public Satellite
{
public:
    friend class TestShip;

    Projectile() {};
    Projectile(Velocity vel, Position pos, Angle ang);
};

