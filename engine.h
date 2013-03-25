#ifndef ENGINE_H
#define ENGINE_H
#include "time/time.h"
#include "physics/object.h"
#include "physics/particle.h"
#include "physics/gravitywell.h"
#include "font/font.h"
#include "map/map.h"
#include "gui/Gui.h"
#include "camera/Camera.h"
#include "input/Joystick.h"
#include "model/ModelMgr.h"
#include "model/RawTriangles.h"
#include "model/Md2.h"
#include "model/C3ds.h"
#include "shader/ShaderMgr.h"
#include "physics/objectmgr.h"
#include "gameplay/SpaceObject.h"
#include "gameplay/Missile.h"
#include "gameplay/Player.h"
#include "gameplay/FactionMgr.h"
#include "terminal/Terminal.h"
#include "physics/ParticleMgr2.h"
#include "gameplay/Scenario.h"

//Graphics Engine Class (singleton)
class GraphicsEngine : public Singleton<GraphicsEngine>
{
	//Sine and cosine lookup tables
	double COS[360];
	double SIN[360];

	//Make sine and cosine lookup tables
	void makeTables();

	//Screen Size
	int width;
	int height;

	//Mouse position variables
	int mouseX,mouseY;

	//SDL Event variable
	SDL_Event event;

	//SDL keyboard variable
	Uint8 *keys;

	Terminal *term;

	bool showTerminal;

	long keyInterval;

	long screenshotKeyInterval;

	bool done;

	bool renderPlayer;

	int numSamples;

	int curSample;

public:

	static std::string version;

	//Constructor - Runs Init() and InitGL()
	GraphicsEngine();

	//Destructor - Runs End() and EndGL()
	virtual ~GraphicsEngine();

	//Initializes OpenGL to standard setup
	bool initGL();

	//User-defined initialization function
	bool init();

	//User-defined end function
	bool end();

	//Ends OpenGL
	bool endGL();

	//Show debugging information - user defined
	void renderDebugInfo();

	//Main function - user defined
	void main();

	//Input handling function - user defined
	void processInput();

	//Take screen shot
	void screenShot();
};



#endif

