#ifndef BEAMWEAPON_H_
#define BEAMWEAPON_H_
#include "../vector/vector.h"
#include "../physics/particle.h"
#include "../physics/objectmgr.h"
#include "../texture/texturemgr.h"

class BeamWeapon
{
	static const double BEAM_LENGTH;
	Object *source;
	Vector position;
	Vector direction;
	double beamWidth;
	double energy;
	double heat;
	bool overHeat;
	bool on;
	void calcHeat();
	void calcEnergy();
public:
	BeamWeapon();
	BeamWeapon(Object *source, Vector position, double beamWidth);
	BeamWeapon(Object *source, double beamWidth);
	void detectCollision();
	void render();
	void activate();
	double getHeat();
	double getEnergy();
	virtual ~BeamWeapon();
};

#endif /*BEAMWEAPON_H_*/
