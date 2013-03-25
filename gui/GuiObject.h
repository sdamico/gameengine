#ifndef GUIOBJECT_H_
#define GUIOBJECT_H_
#include "../res.h"
#include "../font/font.h"
#include "../texture/texturemgr.h"
#include "../vector/vector.h"

class GuiObject
{
	protected:
	std::string id;
	std::string text;
	std::string texName;
	bool clicked;
	long clickTimer;
	Texture *tex;
	Vector posTopLeft;
	Vector posBottomRight;
	GuiObject *children;
	public:
	GuiObject();
	GuiObject(std::string ident, std::string contents, std::string texture, Vector p, Vector d, void (*callbk)(std::string));
	void init(std::string ident, std::string contents, std::string texture, Vector p, Vector d, void (*callbk)(std::string));
	void checkActivation(int mx,int my,int b);
	std::string getID();
	void (*onActivate)(std::string);
	virtual void render();
	virtual ~GuiObject();
};

#endif /*GUIOBJECT_H_*/
