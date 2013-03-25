#ifndef WEAPONLAUNCHER_H_
#define WEAPONLAUNCHER_H_

#include "Missile.h"

class WeaponLauncher
{
	std::string id;
	int maxAmmo;
	int curAmmo;
	unsigned long fireRate;
	unsigned long lastLaunch;
	SpaceObject *parent;
	Vector position;
	Quaternion direction;
public:
	WeaponLauncher();
	WeaponLauncher(std::string id, int maxAmmo, int curAmmo, unsigned long fireRate, SpaceObject *parent, Vector position, Quaternion direction);
	virtual ~WeaponLauncher();
	std::string getID();
	bool launch();
	int getAmmo();
	int getMaxAmmo();
};

#endif /*WEAPONLAUNCHER_H_*/
