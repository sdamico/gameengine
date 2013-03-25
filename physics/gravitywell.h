#ifndef GRAVITYWELL_H
#define GRAVITYWELL_H
#include "objectmgr.h"
#include <iostream>

class GravityWell : public Object
{
	static const float GRAVCONST=6.67e-11;
	public:
	GravityWell();
	GravityWell(std::string id, std::string model, Vector pos, Vector velocity, double mass, float scale);
	~GravityWell();
	void gravity(Object *other);
	void detectCollision(Object *other);
	void action();
};
#endif
