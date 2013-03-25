#ifndef CROSSHAIR_H_
#define CROSSHAIR_H_

//Deprecated - use crosshair built into WeaponDisplay

#include "GuiObject.h"

class Crosshair : public GuiObject
{
public:
	Crosshair();
	Crosshair(std::string ident, Vector topLeft, Vector bottomRight);
	virtual ~Crosshair();

	void render();
};

#endif /*CROSSHAIR_H_*/
