#ifndef SHIP_H_
#define SHIP_H_

#include "SpaceObject.h"
#include "Missile.h"
#include "TargetingSystem.h"
#include "WeaponLauncher.h"
#include "BeamWeapon.h"

class Ship : public SpaceObject {
 protected:
  double hull;
  TargetingSystem *targeting;
  WeaponLauncher *weaponLauncher;
  BeamWeapon *beam;
 public:
  Ship();
  Ship(std::string id, std::string factionID, std::string model, Vector pos,
       Vector velocity, double mass, float scale);
  virtual ~Ship();
  void action();
  void handleCollision(Object *other);
  void fireMissile();
  double getHull();
  virtual void extraRender();
  std::string getTargetID();
};

#endif /*SHIP_H_*/
