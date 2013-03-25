#include "WeaponLauncher.h"

WeaponLauncher::WeaponLauncher() {
  this->id = id;
  this->maxAmmo = 10;
  this->curAmmo = 10;
  this->fireRate = 1000;
  this->parent = NULL;
  this->position = Vector();
  this->direction = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
  lastLaunch = 0;
}

WeaponLauncher::WeaponLauncher(std::string id, int maxAmmo, int curAmmo,
                               unsigned long fireRate, SpaceObject *parent,
                               Vector position, Quaternion direction) {
  this->id = id;
  this->maxAmmo = maxAmmo;
  this->curAmmo = curAmmo;
  this->fireRate = fireRate;
  this->parent = parent;
  this->position = position;
  this->direction = direction;
  lastLaunch = 0;
}

WeaponLauncher::~WeaponLauncher() {
}

std::string WeaponLauncher::getID() {
  return id;
}

bool WeaponLauncher::launch() {
  if (curAmmo > 0 && parent && (SDL_GetTicks() - lastLaunch) > fireRate) {
    std::ostringstream projectileName;
    projectileName << "missile-" << parent->getID() << "-" << rand();
    ObjectMgr::get().add(
        new Missile(
            projectileName.str(),
            "missile",
            parent->getPos()
                + (parent->getRight() * position.x
                    + parent->getUp() * position.y
                    + parent->getLook() * position.z),
            parent->getVelocity(), 50.0f, direction * parent->getQuaternion(),
            parent->getID(), parent->getTargetID(), 100.0f, 0.3f));
    curAmmo--;
    lastLaunch = SDL_GetTicks();
    return true;
  }

  return false;
}

int WeaponLauncher::getMaxAmmo() {
  return maxAmmo;
}

int WeaponLauncher::getAmmo() {
  return curAmmo;
}
