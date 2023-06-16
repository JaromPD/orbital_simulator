#include "ship.h"
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include <list>
#include <cassert>

using namespace std;

class TestShip
{
public:
	void run()
	{
		defaultConstructor();
		nonDefaultConstructor();
		getRadiusTest();
		getIsDeadDead();
		getIsDeadAlive();
		getPositionOne();
	    getPositionOneFive();
	    killAlive();
		killAlreadyDead();
		testDraw();
		testDestroy();
		testSetThrustNoThrust();
		testSetThrustThrust();
		moveStationary();
		moveUp();
		moveDown();
		moveLeft();
		moveRight();
		moveUpLeft();
		moveUpRight();
		moveDownLeft();
		moveDownRight();
		testRotateLeft();
		testRotateRight();
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
		float angularVelocity = 1;
		// Exercise
		Ship ship(vel, pos, ang, angularVelocity);
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
		// Verify angular velocity.
		assert(ship.angularVelocity == angularVelocity);
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

	void testDraw()
	{
		// Setup
		Ship ship;
		ogstreamFake* gout = new ogstreamFake(ship.pos);
		bool thrust = false;
		// Exercise
		ship.draw(gout, thrust);
		// Verify
		
		// Not sure how to verify the Fake draw.

		// Teardown
		delete gout;
	}

	void testDestroy()
	{
		// Setup
		Ship ship;
		list<Satellite *> satellites;
		cout << satellites.size() << endl;
		// Exercise
		ship.destroy(satellites);
		// Verify
		cout << satellites.size() << endl;
		assert(satellites.size() == 2); // Assuming when ship is destroyed, 2 fragments are created.
		// Teardown
	}

	void testRotateLeft()
	{
		// Setup
		Ship ship;
		ship.angularVelocity = 0; // Make sure it's 0.
		// Exercise
		ship.rotateLeft();
		// Verify
		assert(ship.angularVelocity == -0.1);
		// Teardown
	}

	void testRotateRight()
	{
		// Setup
		Ship ship;
		ship.angularVelocity = 0; // Make sure it's 0.
		// Exercise
		ship.rotateRight();
		// Verify
		assert(ship.angularVelocity == 0.1);
		// Teardown
	}

	void testSetThrustNoThrust()
	{
		// Setup
		Ship ship;
		ship.thrust = false;
		// Exercise
		ship.setThrust(false);
		// Verify
		assert(ship.thrust == false);
		// Teardown
	}

	void testSetThrustThrust()
	{
		// Setup
		Ship ship;
		ship.thrust = false;
		// Exercise
		ship.setThrust(true);
		// Verify
		assert(ship.thrust == true);
		// Teardown
	}


	void moveStationary()
	{
		// Setup
		Velocity velocity(0, 0);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;

		Ship ship(velocity, pos, ang, angularVelocity);
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 0);
		assert(ship.pos.y == 0);
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveUp()
	{
		// Setup
		Velocity velocity(0, 1);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 0); // Might have to convert these to meters.
		assert(ship.pos.y == 1); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveDown()
	{
		// Setup
		Velocity velocity(0, -1);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 0); // Might have to convert these to meters.
		assert(ship.pos.y == -1); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveLeft()
	{
		// Setup
		Velocity velocity(-1, 0);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == -1); // Might have to convert these to meters.
		assert(ship.pos.y == 0); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveRight()
	{
		// Setup
		Velocity velocity(1, 0);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 1); // Might have to convert these to meters.
		assert(ship.pos.y == 0); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveUpLeft()
	{
		// Setup
		Velocity velocity(-1, 1);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == -1); // Might have to convert these to meters.
		assert(ship.pos.y == 1); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveUpRight()
	{
		// Setup
		Velocity velocity(1, 1);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 1); // Might have to convert these to meters.
		assert(ship.pos.y == 1); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveDownLeft()
	{
		// Setup
		Velocity velocity(-1, -1);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == -1); // Might have to convert these to meters.
		assert(ship.pos.y == -1); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveDownRight()
	{
		// Setup
		Velocity velocity(1, -1);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0;
		Ship ship(velocity, pos, ang, angularVelocity);
		ship.thrust = true;
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 1); // Might have to convert these to meters.
		assert(ship.pos.y == -1); // Depends in if pos stores is meters or pixels.
		assert(ship.angle.radians == 0);
		// Teardown
	}

	void moveRotateLeft()
	{
		// Setup
		Velocity velocity(0, 0);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = -0.1;
		Ship ship(velocity, pos, ang, angularVelocity);
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 0);
		assert(ship.pos.y == 0);
		assert(ship.angle.radians == -0.1);
		// Teardown
	}

	void moveRotateRight()
	{
		// Setup
		Velocity velocity(0, 0);
		Position pos(0, 0);
		Angle ang(0);
		float angularVelocity = 0.1;
		Ship ship(velocity, pos, ang, angularVelocity);
		// Exercise
		ship.move(1);
		// Verify
		assert(ship.pos.x == 0);
		assert(ship.pos.y == 0);
		assert(ship.angle.radians == 0.1);
		// Teardown
	}

	void input()
	{
		// Setup
		// Exercise
		// Verify
		// Teardown
	}

};