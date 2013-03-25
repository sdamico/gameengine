#ifndef TARGETINGSYSTEM_H_
#define TARGETINGSYSTEM_H_

#include "../physics/objectmgr.h"
#include "../camera/Camera.h"
#include "../font/font.h"

class TargetingSystem
{
	std::string currentTarget;
	Object *parent;
	void drawBox(Object *o, glRGBA color, double *m);
	void drawTargetingBoxes();
public:
	TargetingSystem();
	TargetingSystem(Object *parent);
	void render();
	void nextTarget();
	void prevTarget();
	void targetNearest();
	void targetNearestEnemy();
	void targetNearestAlly();
	void targetNearestMissile();
	Object *getParent();
	Object *getTarget();
	std::string getTargetID();
	virtual ~TargetingSystem();
};

#endif /*TARGETINGSYSTEM_H_*/
