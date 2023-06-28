#pragma once
#include "satellite.h"
#include "velocity.h"
#include "position.h"
#include "uiDraw.h"
#include "angle.h"

class Projectile :
    public Satellite
{
public:
    friend class TestShip;

    Projectile() {};
    Projectile(Velocity vel, Position pos, Angle ang);

    void draw(ogstream* gout) { gout->drawProjectile(pos); };
};

