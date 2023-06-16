#include "ship.h"
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include <cassert>

class TestShip
{
public:
	void run()
	{
		defaultConstructor();
	}

private:
	void defaultConstructor() const
	{
		// Setup
		// Exercise
		Ship ship;
		// Verify
		// Verify velocity.
		assert(ship.velocity.dx == 0);
		assert(ship.velocity.dy == 0);
		// Verify position.
		assert(ship.pos.x == 0);
		assert(ship.pos.y == 0);
		// Verify angle.
		assert(ship.angle.radians == 0);
		// Verify angular velocity.
		assert(ship.angularVelocity == 0);
		// Verify death boolean.
		assert(ship.dead == false);
		// Verify radius.
		assert(ship.radius == 5); // Just assuming Ship's radius is 5.
		// Teardown
	}

	void nonDefaultConstructor()
	{
		// Setup
		Velocity vel(1, 1);
		Position pos(1, 1);
		Angle ang(1);
		// Exercise
		Ship ship(vel, pos, ang);
		// Verify
		// Verify velocity.
		assert(ship.velocity.dx == 1);
		assert(ship.velocity.dy == 1);
		// Verify position.
		assert(ship.pos.x == 1);
		assert(ship.pos.y == 1);
		// Verify angle.
		assert(ship.angle.radians == 1);
		// Verify angular velocity.
		assert(ship.angularVelocity == 0);
		// Verify death boolean.
		assert(ship.dead == false);
		// Verify radius.
		assert(ship.radius == 1);
		// Teardown
	}

	void getRadiusTest()
	{
		// Setup
		Ship ship;
		// Exercise
		float radius = ship.getRadius();
		// Verify
		assert(radius == 5); // Again assuming radius is 5.
		assert(radius == ship.radius);
		// Teardown
	}

	void getIsDeadDead()
	{
	// Setup
		Ship ship;
		ship.dead = true;
		// Exercise
		bool dead = ship.isDead();
		// Verify
		assert(dead == true);
		// Teardown
	}

	void getIsDeadAlive()
	{
		// Setup
		Ship ship;
		ship.dead = false;
		// Exercise
		bool dead = ship.isDead();
		// Verify
		assert(dead == false);
		// Teardown
	}

	void getPositionOne()
	{
		// Setup
		Ship ship;
		ship.pos.x = 1;
		ship.pos.y = 1;
		// Exercise
		Position pos = ship.getPosition();
		// Verify
		assert(pos.x == 1);
		assert(pos.y == 1);
		assert(pos.x == ship.pos.x);
		assert(pos.y == ship.pos.y);
		// Teardown
	}

	void getPositionOneFive()
	{
		// Setup
		Ship ship;
		ship.pos.x = 1;
		ship.pos.y = 5;
		// Exercise
		Position pos = ship.getPosition();
		// Verify
		assert(pos.x == 1);
		assert(pos.y == 5);
		assert(pos.x == ship.pos.x);
		assert(pos.y == ship.pos.y);
		// Teardown
	}

	void killAlive()
	{
		// Setup
		Ship ship;
		ship.dead = false;
		// Exercise
		ship.kill();
		// Verify
		assert(ship.dead == true);
		// Teardown
	}

	void killAlreadyDead()
	{
		// Setup
		Ship ship;
		ship.dead = true;
		// Exercise
		ship.kill();
		// Verify
		assert(ship.dead == true);
		// Teardown
	}

	void draw()
	{
		// Setup
		Ship ship;
		ogstreamFake* gout = new ogstreamFake(ship.pos);
		bool thrust = false;
		// Exercise
		ship.draw(gout, thrust);
		// Verify
		// Teardown
	}

	void destroy()
	{
		// Setup
		// Exercise
		// Verify
		// Teardown
	}

	void move()
	{
		// Setup
		// Exercise
		// Verify
		// Teardown
	}

	void input()
	{
		// Setup
		// Exercise
		// Verify
		// Teardown
	}

	void test_display()
	{
	 // OGSTREAM has dummies and fakes. DO FAKE
	}

};