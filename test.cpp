/*********************************************************************
Written By: Jarom Diaz
Last Modified: 06/17/2023
Description: This file contains the test cases for the oribtal program.
*********************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testShip.h"
#include "testAngle.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
	TestAngle().run();
	TestPosition().run();
	TestShip().run();
}
