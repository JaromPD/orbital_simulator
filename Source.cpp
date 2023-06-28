#define _USE_MATH_DEFINES
double SECONDS_PER_DAY = 86400;
int FRAME_RATE = 30;
double SECONDS_PER_FRAME = 48;
#include <cassert>      // for ASSERT
#include <list>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include"test.h"
#include "position.h"      // for POINT
#include "satellite.h"
#include "ship.h"
#include "star.h"
#include <math.h>

using namespace std;

class Position;

class Simulation {
public:
    Simulation(Position ptUpperRight) {
        // Create the ship
        //Angle ang(-3.141519 / 6);
        Angle ang(0);
        Velocity vel(-3100, ang);
        Position pos(21082000, 36515095.125);
        ship = new Ship(vel, pos, ang, 0);
        //satellites.push_back(ship);

        for (int i = 0; i < 2000; i++)
        {
            Star *newStar = new Star();
            stars.push_back(newStar);
        }

        angleEarth = 0.0;

    };

    void draw(ogstream* gout) {

        for (auto& star : stars) {
			star->draw(gout);
		};

        for (auto& satellite : satellites) {

            satellite->draw(gout);

        };

        ship->draw(gout);

        Position earthPt(0, 0);
        gout->drawEarth(earthPt, angleEarth);
    };

    void move() {
    
        ship->move(SECONDS_PER_FRAME);

        for (auto& satellite : satellites) {

            satellite->move(SECONDS_PER_FRAME);

        };

        // Move the Earth
        angleEarth += -(((2 * M_PI) / FRAME_RATE) * (1440 / SECONDS_PER_DAY));

    };

    void input(const Interface* pUI) {
    
        if (pUI->isUp())
        {
        }

        if (pUI->isDown())
        {
            ship->setThrust(true);
        }
        else
        {
            ship->setThrust(false);
        }

        if (pUI->isLeft())
        {
            ship->rotateLeft();
        }

        if (pUI->isRight())
        {
            ship->rotateRight();
		}

        if (pUI->isSpace())
        {
			Projectile* newProjectile = ship->fire();
			satellites.push_back(newProjectile);
        }
    };

private:
    list<Satellite*> satellites;
    float angleEarth;
    list<Star*> stars;
    Ship* ship;
};

void callBack(const Interface* pUI, void* p)
{
    Simulation* pSim = (Simulation*)p;
    Position pt;
    ogstream *gout = new ogstream();

    pSim->input(pUI);
    pSim->move();
    pSim->draw(gout);

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
    //testRunner();

    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);
    Interface ui(0, NULL,
        "Demo",   /* name on the window */
        ptUpperRight);

    // Initialize the demo
    Simulation sim(ptUpperRight);

    // set everything into action
    ui.run(callBack, &sim);


    return 0;
}