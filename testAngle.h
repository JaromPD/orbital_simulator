/*********************************************************************
Written By: Jarom Diaz
Last Modified: 06/17/2023
Description: This file contains the test cases for the angle class.
*********************************************************************/

#pragma once
#include "angle.h"
#include <cassert>
#define M_PI 3.14159265358979323846

class TestAngle
{
public:
	void run()
	{
		defaultConstructor();
		setRadiansZero();
		setRadiansPi();
		setRadians2Pi();
		setRadians3Pi();
		setRadiansNegPi();
		setDegreesZero();
		setDegrees180();
		setDegrees360();
		setDegrees540();
		setDegreesNeg180();
		setDxDy();
		setDxDy3piFourth();
		setDxDyPi();
		setDxDyZeroPi();
		setDxDyZero();
		setDegreesZero();
		getDegreesPi();
		getDegrees2Pi();
		getDegrees3Pi();
		getDegreesNegPi();
		getRadiansZeroPi();
		getRadiansPi();
		getRadians2Pi();
		getRadians3Pi();
		getRadiansNegPi();
		setDown();
		setUp();
		setLeft();
		setRight();
		rotatePi();
		rotate2Pi();
		rotate3Pi();
		rotateNegPi();
		rotateNoPi();
	}

private:
	void defaultConstructor()
	{
		// Setup
		// Excercise
		Angle d;
		// Verify
		assert(d.radians == 0.00);
		// Teardown
	}

	void setRadiansZero()
	{
		// Setup
		Angle d;
		// Excercise
		d.setRadians(0);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setRadiansPi()
	{
		// Setup
		Angle d;
		// Excercise
		d.setRadians(M_PI);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setRadians2Pi()
	{
		// Setup
		Angle d;
		// Excercise
		d.setRadians(2 * M_PI);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setRadians3Pi()
	{
		// Setup
		Angle d;
		// Excercise
		d.setRadians(3 * M_PI);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setRadiansNegPi()
	{
		// Setup
		Angle d;
		// Excercise
		d.setRadians(-M_PI);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDegreesZero()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDegrees(0);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setDegrees180()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDegrees(180);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDegrees360()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDegrees(360);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setDegrees540()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDegrees(540);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDegreesNeg180()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDegrees(-180);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDxDy()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDxDy(1, 1);
		// Verify
		assert(d.radians == M_PI / 4);
		// Teardown
	}

	void setDxDy3piFourth()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDxDy(-1, -1);
		// Verify
		assert(d.radians == (3 * M_PI) / 4);
		// Teardown
	}

	void setDxDyPi()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDxDy(-1, 0);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDxDyZeroPi()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDxDy(1, 0);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setDxDyZero()
	{
		// Setup
			Angle d;
			// Excercise
			d.setDxDy(0, 1);
			// Verify
			assert(d.radians == M_PI / 2);
			// Teardown
		}

	void getDegreesPiHalf()
	{
		// Setup
		Angle d;
		// Excercise
		d.setDxDy(0, 1);
		// Verify
		assert(d.getDegrees() == 0);
		// Teardown
	}

	void getDegreesPi()
	{
		// Setup
		Angle d;
		d.radians = M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 180);
		// Teardown
	}

	void getDegrees2Pi()
	{
		// Setup
		Angle d;
		d.radians = 2 * M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 0);
		// Teardown
	}

	void getDegrees3Pi()
	{
		// Setup
		Angle d;
		d.radians = 3 * M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 180);
		// Teardown
	}

	void getDegreesNegPi()
	{
		// Setup
		Angle d;
		d.radians = -M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 180);
		// Teardown
	}

	void getRadiansZeroPi()
	{
		// Setup
		Angle d;
		d.radians = 0;
		// Excercise
		// Verify
		assert(d.getRadians() == 0);
		// Teardown
	}

	void getRadiansPi()
	{
		// Setup
		Angle d;
		d.radians = M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == M_PI);
		// Teardown
	}

	void getRadians2Pi()
	{
		// Setup
		Angle d;
		d.radians = 2 * M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == 2 * M_PI);
		// Teardown
	}

	void getRadians3Pi()
	{
		// Setup
		Angle d;
		d.radians = 3 * M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == 3 * M_PI);
		// Teardown
	}

	void getRadiansNegPi()
	{
		// Setup
		Angle d;
		d.radians = -1 * M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == -1 * M_PI);
		// Teardown
	}

	void setDown()
	{
		// Setup
		Angle d;
		d.radians = 1;
		// Excercise
		d.setDown();
		// Verify
		assert(d.getRadians() == M_PI);
		// Teardown
	}

	void setUp()
	{
		// Setup
		Angle d;
		d.radians = 1;
		// Excercise
		d.setUp();
		// Verify
		assert(d.getRadians() == 0);
		// Teardown
	}

	void setLeft()
	{
		// Setup
		Angle d;
		d.radians = 1;
		// Excercise
		d.setLeft();
		// Verify
		assert(d.getRadians() == 3 * (M_PI / 2));
		// Teardown
	}

	void setRight()
	{
		// Setup
		Angle d;
		d.radians = 1;
		// Excercise
		d.setRight();
		// Verify
		assert(d.getRadians() == M_PI / 2);
		// Teardown
	}

	void rotatePi()
	{
		// Setup
		Angle d;
		d.radians = 0;
		// Excercise
		d.rotate(M_PI);
		// Verify
		assert(d.getRadians() == M_PI);
		// Teardown
	}

	void rotate2Pi()
	{
		// Setup
		Angle d;
		d.radians = 0;
		// Excercise
		d.rotate(2 * M_PI);
		// Verify
		assert(d.getRadians() == 0);
		// Teardown
	}

	void rotate3Pi()
	{
		// Setup
		Angle d;
		d.radians = 0;
		// Excercise
		d.rotate(3 * M_PI);
		// Verify
		assert(d.getRadians() == 3 * M_PI);
		// Teardown
	}

	void rotateNegPi()
	{
		// Setup
		Angle d;
		d.radians = 0;
		// Excercise
		d.rotate(-1 * M_PI);
		// Verify
		assert(d.getRadians() == -1 * M_PI);
		// Teardown
	}

	void rotateNoPi()
	{
		// Setup
		Angle d;
		d.radians = 0;
		// Excercise
		d.rotate(0);
		// Verify
		assert(d.getRadians() == 0);
		// Teardown
	}
};