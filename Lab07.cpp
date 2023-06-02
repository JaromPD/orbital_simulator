/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#define _USE_MATH_DEFINES
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <cassert>
#include <cmath>       // For atan2
using namespace std;

int RADIUS_OF_EARTH = 6378000;
double ROTATIONS_PER_FRAME = 1 / 1800;
int SECONDS_PER_FRAME = 48; // Should be 48
double SECONDS_PER_DAY = 86400;

double FRAME_RATE = 30;

int GEO_DISTANCE = 42164000;
int GEO_SPEED = 3100;
int ANGLE_DEGREES = 30;
double ANGLE_RADIANS = 0.524;
int RADIUS_EARTH = 6378000;

double GRAVITY_EARTH = -9.8067;

/**********************************************************************************
 * GET ANGLE RADIANS
 * 
 * angle_degrees = angle in degrees
**********************************************************************************/

double getAngleRadians(double angle_degrees)
{
    return (angle_degrees * M_PI / 180);
}


/**********************************************************************************
 * GET ANGLE DEGREES
 * 
 * angle_radians = angle in radians
**********************************************************************************/
double getAngleDegrees(double angle_radians)
{
	return (angle_radians * 180 / M_PI);
}

/**********************************************************************************
 * GET X COMPONENT
 * 
 * totalComponent = total component of the vector
**********************************************************************************/
double getXComponent(double totalComponent, double angleDegrees)
{
    return (totalComponent * cos(getAngleRadians(angleDegrees)));
}

/**********************************************************************************
 * GET Y COMPONENT
 * 
 * totalComponent = total component of the vector
**********************************************************************************/
double getYComponent(double totalComponent, double angleDegrees)
{
    return (totalComponent * sin(getAngleRadians(angleDegrees)));
}

/**********************************************************************************
 * GET GRAVITY
 * 
 * h = height above the earth in meters
 * g = gravity
 * r = radius of the earth: 6,378,000 m
**********************************************************************************/
double getGravity(double h) {
    double g = GRAVITY_EARTH;
    int r = RADIUS_EARTH;
    return g * pow((r / (r + h)), 2);
}

/**********************************************************************************
 * GET HEIGHT ABOVE EARTH
 * 
 * h = height above the earth in meters
 * x = horizontal position of the satellite where the center of the earth is 0
 * y = vertical position of the satellite where the center of the earth is 0
 * r = radius of the earth: 6,378,000 m
**********************************************************************************/
double getHeightAboveEarth(double x, double y)
{
    int r = RADIUS_EARTH;

    return(sqrt(pow(x, 2) + pow(y, 2)) - r);
}

/**********************************************************************************
 * GET DIRECTION GRAVITY
 * 	
 * d = direction of the pull of gravity, in radians
 * xe = horizontal position of the center of the earth: 0 m
 * ye = vertical position of the center of the earth: 0 m
 * xs = horizontal position of the satellite in meters
 * ys = vertical position of the satellite in meters
**********************************************************************************/
double getDirectionGravity(double xs, double ys)
{
    int xe = 0;
    int ye = 0;

    return(atan2((xe - xs), (ye - ys)));
}

/**********************************************************************************
 * GET HORIZONTAL ACCELERATION
 * 
 * ddx = horizontal component of acceleration
 * a = total acceleration
 * angle = angle (0° is up) of the direction of acceleration
**********************************************************************************/
double getHorizontalAcceleration( double a, double angle)
{
    return (a * sin(angle));
}

/**********************************************************************************
 * GET VERTICAL ACCELERATION
 *
 * ddy = horizontal component of acceleration
 * a = total acceleration
 * angle = angle (0° is up) of the direction of acceleration
**********************************************************************************/
double getVerticalAcceleration(double a, double angle)
{
    return (a * cos(angle));
}

struct DxDy {
    double dx;
    double dy;
};

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      //ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      // Start the sputnik calculations for GEO.

      // Set initial POS
      ptGPS.setMetersX(getYComponent(GEO_DISTANCE, ANGLE_DEGREES));
      cout << "X: " << ptGPS.getMetersX() << endl;
      ptGPS.setMetersY(getXComponent(GEO_DISTANCE, ANGLE_DEGREES));
      cout << "Y: " << ptGPS.getMetersY() << endl;

      DxDyGPS.dx = getXComponent(GEO_SPEED, ANGLE_DEGREES - 180);
      DxDyGPS.dy = getYComponent(GEO_SPEED, ANGLE_DEGREES);

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   DxDy DxDyGPS;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   Position *ptGPS = &pDemo->ptGPS;
   DxDy *DxDyGPS = &pDemo->DxDyGPS;
   //double initialDX = &pDemo->GPSDxDy.dx;
   //double initialDY = &pDemo->GPSDxDy.dy;

   // Calculate the height
   //  1:36 - 3:36

   double gpsHeight = getHeightAboveEarth(ptGPS->getMetersX(), ptGPS->getMetersY());
   cout << "GPS Height: " << gpsHeight << endl;
   cout << "Similarity: " << (gpsHeight + RADIUS_EARTH) - GEO_DISTANCE << endl;
   // Calculate the acceleration
   // 3:39 - 5:44

   double gpsCurrGravity = getGravity(gpsHeight);
   cout << "GPS Gravity: " << gpsCurrGravity << endl;

   double currDirectionGravity = getDirectionGravity(ptGPS->getMetersX(), ptGPS->getMetersY());
   cout << "GPS Gravity Direction: " << currDirectionGravity << endl;

   double gpsCurrGravityDDY = -getVerticalAcceleration(gpsCurrGravity, currDirectionGravity);
   double gpsCurrGravityDDX = -getHorizontalAcceleration(gpsCurrGravity, currDirectionGravity);
   cout << "GPS Gravity DDX: " << gpsCurrGravityDDX << endl;
   cout << "GPS Gravity DDY: " << gpsCurrGravityDDY << endl;

   // Calculate the velocity
   // 5:50 - 

   //double gpsCurrVelocityDY = getYComponent(GEO_SPEED, getAngleDegrees(currDirectionGravity));
   double gpsCurrVelocityDY = DxDyGPS->dy;
   cout << "GPS Velocity DY: " << gpsCurrVelocityDY << endl;
   //double gpsCurrVelocityDX = getXComponent(GEO_SPEED, getAngleDegrees(currDirectionGravity));
   double gpsCurrVelocityDX = DxDyGPS->dx;
   cout << "GPS Velocity DX: " << gpsCurrVelocityDX << endl;

   double gpsNewVelocityDY = (gpsCurrVelocityDY + (gpsCurrGravityDDY * SECONDS_PER_FRAME));
   DxDyGPS->dy = gpsNewVelocityDY;
   cout << "GPS New Velocity DY: " << gpsNewVelocityDY << endl;
   double gpsNewVelocityDX = (gpsCurrVelocityDX + (gpsCurrGravityDDX * SECONDS_PER_FRAME));
   DxDyGPS->dx = gpsNewVelocityDX;
   cout << "GPS New Velocity DX: " << gpsNewVelocityDX << endl;

   double newX = ptGPS->getMetersX() + (gpsNewVelocityDX * SECONDS_PER_FRAME) + (0.5 * gpsCurrGravityDDX * pow(SECONDS_PER_FRAME, 2));
   double newY = ptGPS->getMetersY() + (gpsNewVelocityDY * SECONDS_PER_FRAME) + (0.5 * gpsCurrGravityDDY * pow(SECONDS_PER_FRAME, 2));

   ptGPS->setMetersX(newX);
   ptGPS->setMetersY(newY);
   cout << "GPS New X: " << ptGPS->getMetersX() << endl;
   cout << "GPS New Y: " << ptGPS->getMetersY() << endl << endl;
  

   // rotate the earth
   //pDemo->angleEarth += 0.01;
   pDemo->angleEarth += -(((2 * M_PI) / FRAME_RATE) * (1440 / SECONDS_PER_DAY));
   cout << -(((2*M_PI) / FRAME_RATE) * (1440 / SECONDS_PER_DAY)) << endl;
   cout << "Earth Angle: " << pDemo->angleEarth << endl;
   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
