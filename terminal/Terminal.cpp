#include "Terminal.h"

Terminal::Terminal() {
  keyUp = true;
  repeating = false;
  lastKeyPress = 0;
  numLines = 0;
  debugState = false;
  SDL_EnableUNICODE(1);

  //Py_Initialize();
}

Terminal::~Terminal() {
  //Py_Finalize();
}

void Terminal::runCommand(std::string command) {
  if (command == "toggledebug") {
    debugState = !debugState;
  }
  /*else
   {
   //std::cout<<command<<std::endl;
   PyRun_SimpleString(("result="+command).c_str());
   PyObject * module = PyImport_AddModule("__main__"); // borrowed reference
   
   assert(module);                                     // __main__ should always exist
   PyObject * dictionary = PyModule_GetDict(module);   // borrowed reference
   assert(dictionary);                                 // __main__ should have a dictionary
   PyObject * result = PyDict_GetItemString(dictionary, "result");     // borrowed reference
   
   assert(result);                                     // just added result
   assert(PyString_Check(result));                        // result should be an integer
   char *result_value = PyString_AS_STRING(result);          // already checked that it is an int
   history+=result_value;
   history+="\n";
   numLines++;
   }*/
}

void Terminal::moveCursor(int r, int c) {

}

void Terminal::render() {
  char temp[128];
  unsigned int strIndex = 0;
  std::stringstream sstr;
  sstr << history;

  for (strIndex = 0; !sstr.eof(); strIndex++) {
    glRasterPos2f(-1.0f, 0.95f - 0.05f * (strIndex - numLines + 10));
    sstr.getline(temp, 128);
    FontLib::get().glPrint(temp);
  }
  glRasterPos2f(-1.0f, 1.0f - 0.05f * (11.0f));
  if (SDL_GetTicks() % 1000 < 500)
    FontLib::get().glPrint((">>> " + curLine + "|").c_str());
  else
    FontLib::get().glPrint((">>> " + curLine).c_str());
}

void Terminal::clear() {
  curLine = "";
}

bool Terminal::getDebugState() {
  return debugState;
}

void Terminal::getInput(SDL_Event *event) {
  SDL_PollEvent(event);
  char lastChar = '\0';
  if (curLine.length() > 0) {
    lastChar = curLine[curLine.length() - 1];
  }
  if (event) {
    if (event->type == SDL_KEYDOWN) {
      switch (event->key.keysym.sym) {
        case SDLK_RETURN:
          if (curLine != "") {
            history += ">>> " + curLine + "\n";
            runCommand(curLine);
            curLine = "";
            numLines++;
          }
          break;
        case SDLK_BACKSPACE:
          if (curLine.length())
            curLine.erase(curLine.length() - 1);
          break;
        default:
          if (event->key.keysym.sym >= 32 && event->key.keysym.sym <= 126
              && event->key.keysym.sym != 96) {
            if ((char) event->key.keysym.unicode == lastChar) {
              if (SDL_GetTicks() - lastKeyPress > REPEAT_INITIAL_DELAY) {
                curLine += lastChar;
                repeating = !repeating;
                lastKeyPress = SDL_GetTicks();
              } else if (SDL_GetTicks() - lastKeyPress > REPEAT_DELAY
                  && repeating) {
                curLine += lastChar;
                lastKeyPress = SDL_GetTicks();
              } else if (SDL_GetTicks() - lastKeyPress > REPEAT_DELAY * 4) {
                curLine += (char) event->key.keysym.unicode;
                repeating = false;
                lastKeyPress = SDL_GetTicks();
              }
            } else {
              curLine += (char) event->key.keysym.unicode;
              repeating = false;
              lastKeyPress = SDL_GetTicks();
            }
          }

          break;
      }

    } else {
      if ((char) event->key.keysym.unicode == lastChar) {
        lastChar = '\0';
        repeating = false;
      }
    }

  }
}
