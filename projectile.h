#pragma once
#include "satellite.h"

class Projectile :
    public Satellite
{
public:
    friend class TestShip;
};

