#include "engine.h"

std::string GraphicsEngine::version = "0.1.1";

GraphicsEngine::GraphicsEngine() {
  std::cout << "[Starting Core Engine]" << std::endl;

  initGL();
  init();
}

//Destructor automatically calls End(); and EndGL();
GraphicsEngine::~GraphicsEngine() {
  end();
  endGL();
}

//Initializes OpenGL to standard setup
bool GraphicsEngine::initGL() {
  //Initialize SDL Video and Joystick
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);

  //Set video mode swidth*sheight*userBPP
  SDL_SetVideoMode(
      swidth, sheight, 0,
      SDL_OPENGL | SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER );

  width = swidth;
  height = sheight;

  //Enable keyboard key repeat
  SDL_EnableKeyRepeat(1, 1);

  //Get mouse position
  SDL_GetMouseState(&mouseX, &mouseY);

  //Set OpenGL viewport to swidth*sheight
  glViewport(0, 0, swidth, sheight);

  //Enable double buffering
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  //Hide mouse
  SDL_ShowCursor(SDL_DISABLE);

  //Enable Texturing
  glEnable(GL_TEXTURE_2D);

  //Clear the depth buffer to 1.0f
  glClearDepth(1.0f);

  //Enable depth testing
  glEnable(GL_DEPTH_TEST);

  //Sets Depth test function to Less than or equal to
  glDepthFunc(GL_LEQUAL);

  //Enable texture blending
  glEnable(GL_BLEND);

  //Set blend function
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);

  //Fast point smoothing
  glHint(GL_POINT_SMOOTH_HINT, GL_FASTEST);

  //Projection matrix mode
  glMatrixMode(GL_PROJECTION);

  //Reset it
  glLoadIdentity();

  //Set a nice perspective ratio
  GLfloat ratio = (GLfloat) swidth / (GLfloat) sheight;
  //gluPerspective( 45.0f, ratio, 0.1f, 1000.0f );
  gluPerspective(60.0f, ratio, 0.8f, 1200000.0f);
  //Nice perpective correction
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  //Return to modelview matrix
  glMatrixMode(GL_MODELVIEW);

  //Enable lighting
  glEnable(GL_LIGHTING);

  //Enable smooth shading
  glShadeModel(GL_SMOOTH);

  //seed the randomizer
  srand(SDL_GetTicks());

  //clear background color to black
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  //Make sine and cosine tables
  makeTables();

  term = new Terminal();

  return true;
}

//Ends OpenGL
bool GraphicsEngine::endGL() {
  delete term;

  //Disable any arrays that may be enabled
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);

  //Delete any display lists
  glDeleteLists(1, 1);

  //Quit SDL
  SDL_Quit();

  std::cout << "[Ending Core Engine]" << std::endl;
  return true;
}

//Fill in SIN and COS for each degree
void GraphicsEngine::makeTables() {
  for (int i = 0; i < 360; i++) {
    SIN[i] = sin(DEG2RAD(i));
    COS[i] = cos(DEG2RAD(i));
  }
}

void GraphicsEngine::screenShot() {
  Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif

  SDL_Surface *screen = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32,
                                             rmask, gmask, bmask, amask);

  unsigned int *pixels = new unsigned int[width * height];

  glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

  unsigned int *pixelsFlipped = new unsigned int[width * height];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixelsFlipped[i * width + j] = pixels[(height - i) * width + j];
    }
  }

  delete pixels;
  screen->pixels = pixelsFlipped;

  std::ostringstream screenName;
  screenName << "screenshot-" << GlobalTime::get().getSeconds() << ".bmp";
  SDL_SaveBMP(screen, screenName.str().c_str());
  SDL_FreeSurface(screen);
}

