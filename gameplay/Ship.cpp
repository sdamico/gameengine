#include "Ship.h"

Ship::Ship() {
  targeting = new TargetingSystem(this);
}

Ship::Ship(std::string id, std::string factionID, std::string model, Vector pos,
           Vector velocity, double mass, float scale)
    : SpaceObject(id, factionID, model, pos, velocity, mass, scale) {
  //top speed variable, change to desired top speed
  topAccel = 50.0f;
  topTurnSpeed = 60.0f;
  thrustVecThreshold = 10.0f;

  //q.createFromAxisAngle(up.x,up.y,up.z,-150.0f);

  objectType = "ship";

  //build(id, model, pos, velocity, mass, scale);

  hull = 100.0f;

  targeting = new TargetingSystem(this);

  weaponLauncher = new WeaponLauncher("Missile Launcher", 20, 20, 1000, this,
                                      Vector(0.1f * size * scale, 0.0f, 0.0f),
                                      Quaternion(0, 0, 0, 1));
  beam = new BeamWeapon(this, Vector(-3.0f, -3.5f, 0.0f), 1.0f);
}

Ship::~Ship() {
  delete weaponLauncher;
  delete targeting;
  if (beam)
    delete beam;
}

void Ship::fireMissile() {
  weaponLauncher->launch();
}

void Ship::handleCollision(Object *other) {
  //Beam hit
  if (!other) {
    hull -= GlobalTime::get().frameSec * 75.0f;
    ParticleMgr::get().startExplosion("engine", 36, 0.1f, 200.0f, 700, pos,
                                      velocity, 5);
    if (hull < 0.0f)
      done = true;
  } else if (other->getSource() != id) {
    done = true;
    ParticleMgr::get().startExplosion("engine", 36, 0.1f, 500.0f, 700, pos,
                                      velocity, 10);
  }

}

void Ship::action() {

  Object *p = targeting->getTarget();
  if (p) {
    double delta = (p->getPos() - pos).magnitude();
    if (delta < 100000.0f) {
      if (((p->getVelocity() - velocity).magnitude() < delta / 6.0f)
          || delta > 5000.0f)
        track(p->getID());
      else if ((p->getVelocity() - velocity).magnitude() < 50.0f)
        matchVelocity(p->getID());
      else
        pointTowards(p->getID());

      double ang = look.angle(p->getPos() - pos);
      if (ang < 1.0f) {
        beam->activate();
      } else if (ang < 15.0f && delta < 4000.0f)
        if ((int) GlobalTime::get().fps != 0)
          if ((rand() % ((int) GlobalTime::get().fps * 2)) == 0) {
            weaponLauncher->launch();
            targeting->targetNearestEnemy();
          }

    } else
      targeting->targetNearestEnemy();
  } else {
    if (pos.magnitude() > 20000.0f) {
      if (velocity.magnitude() > 50.0f)
        stop();
      else
        track(Vector());
    }
    targeting->targetNearestEnemy();
  }
}

std::string Ship::getTargetID() {
  if (targeting)
    return targeting->getTargetID();
  return "";
}

double Ship::getHull() {
  return hull;
}

void Ship::extraRender() {
  beam->render();
}
