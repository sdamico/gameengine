#ifndef BUTTON_H_
#define BUTTON_H_

#include "GuiObject.h"

class Button : public GuiObject
{
public:
	Button();
	Button(std::string ident, std::string contents, std::string texture, Vector p, Vector d, void (*callbk)(std::string));
	void render();
	virtual ~Button();
};

#endif /*BUTTON_H_*/
