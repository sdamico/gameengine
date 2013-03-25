#ifndef SPACEOBJECT_H_
#define SPACEOBJECT_H_

#include "../physics/objectmgr.h"
#include "../physics/particle.h"
#include "../time/time.h"
#include "FactionMgr.h"

class SpaceObject : public Object
{
protected:
	float topAccel;
	float topTurnSpeed;
	float thrustVecThreshold;
public:

	SpaceObject();
	SpaceObject(std::string id, std::string factionID, std::string model, Vector pos, Vector velocity, double mass, float scale);
	virtual ~SpaceObject();
	void action();
	void track(std::string objectName);
	void track(Vector p);
	void pointTowards(std::string objectName);
	void stop();
	void thrust(double percentage);
	void matchVelocity(std::string objectName);
	void handleCollision(Object *other);
	virtual std::string getTargetID();
};

#endif /*SPACEOBJECT_H_*/
