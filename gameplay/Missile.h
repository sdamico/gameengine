#ifndef MISSILE_H_
#define MISSILE_H_

#include "SpaceObject.h"

class Missile : public SpaceObject
{
	std::string target;
	long startTime;
	long homeTime;
public:
	Missile();
	Missile(std::string id, std::string model, Vector pos, Vector velocity, float launchSpeed, Quaternion q, std::string source, std::string target, double mass, float scale);
	virtual ~Missile();
	void handleCollision(Object *other);
	void action();	
	std::string getTargetID();
};

#endif /*MISSILE_H_*/
