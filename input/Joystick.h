#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_
#include "../res.h"
#include "../mm/singleton.h"

class Joystick : public Singleton <Joystick>
{
	SDL_Joystick *joy;
	int numAxes;
	int numButtons;
	int numHats;
	
public:
	bool enabled;
	Joystick();
	int getNumAxes();
	int getNumButtons();
	int getNumHats();
	int getAxis(int axis);
	int getButton(int button);
	int getHat(int hat);
	virtual ~Joystick();
};

#endif //_JOYSTICK_H_
