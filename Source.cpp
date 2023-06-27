#define _USE_MATH_DEFINES
#include <cassert>      // for ASSERT
#include <list>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include"test.h"
#include "position.h"      // for POINT
#include "satellite.h"
#include "ship.h"
#include <math.h>

#define SECONDS_PER_DAY 86400
#define FRAME_RATE 30;

using namespace std;

class Position;

class Simulation {
public:
    Simulation(Position ptUpperRight) {
    
        Ship *ship = new Ship();

        satellites.push_back(ship);

        angleEarth = 0.0;

    };

    void draw(ogstream* gout) {
        for (list<Satellite*>::iterator it = satellites.begin(); it != satellites.end(); ++it)
		    {
			    (*it)->draw();
		    }

        cout << "Called Move" << endl;
        Position earthPt(0, 0);
        gout->drawEarth(earthPt, angleEarth);
    };

    void move() {
    
        angleEarth += -(((2 * M_PI) / FRAME_RATE) * (1440 / SECONDS_PER_DAY));

    };

    void input() {};

private:
    list<Satellite*> satellites;
    float angleEarth;
};

void callBack(const Interface* pUI, void* p)
{
    Simulation* pSim = (Simulation*)p;
    Position pt;
    ogstream *gout = new ogstream();

    pSim->input();
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
    testRunner();

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