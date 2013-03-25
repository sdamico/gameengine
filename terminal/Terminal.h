#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "../res.h"
#include "../font/font.h"
//include <python2.5/Python.h>

class Terminal {
  static const long REPEAT_INITIAL_DELAY = 5000;
  static const long REPEAT_DELAY = 30;
  std::string history;
  std::string curLine;
  int position;
  long lastKeyPress;
  bool keyUp;
  bool repeating;
  bool debugState;
  int numLines;
  void runCommand(std::string command);
  void moveCursor(int r, int c);
 public:
  Terminal();
  virtual ~Terminal();
  void render();
  void clear();
  void getInput(SDL_Event *event);
  bool getDebugState();
};

#endif /*TERMINAL_H_*/
