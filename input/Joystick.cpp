#include "Joystick.h"

Joystick::Joystick() {
  if (SDL_NumJoysticks() > 0) {
    // Open joystick
    joy = NULL;
    joy = SDL_JoystickOpen(0);

    if (!joy) {
      std::cerr << "[Joystick Not Available]" << std::endl;
      enabled = false;
      return;
    }
  }

  numAxes = SDL_JoystickNumAxes(joy);
  if (numAxes <= 0) {
    enabled = false;
    std::cerr << "[Joystick Not Available]" << std::endl;
    return;
  }
  numButtons = SDL_JoystickNumButtons(joy);
  numHats = SDL_JoystickNumHats(joy);
  std::cout << "[Starting Joystick: " << numAxes << " Axes]" << std::endl;
  enabled = true;

}
int Joystick::getNumAxes() {
  return numAxes;
}
int Joystick::getNumButtons() {
  return numButtons;
}
int Joystick::getNumHats() {
  return numHats;
}
int Joystick::getAxis(int axis) {
  return SDL_JoystickGetAxis(joy, axis);
}
int Joystick::getButton(int button) {
  return SDL_JoystickGetButton(joy, button);
}
int Joystick::getHat(int hat) {
  return SDL_JoystickGetHat(joy, hat);
}
Joystick::~Joystick() {

  if (SDL_JoystickOpened(0)) {
    std::cout << "[Ending Joystick]" << std::endl;
    SDL_JoystickClose(joy);
  }
}
