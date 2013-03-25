#include "gravitywell.h"

GravityWell::GravityWell() {
  right = Vector(1.0f, 0.0f, 0.0f);
  up = Vector(0.0f, -1.0f, 0.0f);
  look = Vector(0.0f, 0.0f, -1.0f);
  q.createFromAxisAngle(look.x, look.y, look.z, 0.0f);
  source = "";
  objectType = "generic";
  done = false;
  collisionID = "";
  lastCollision = 0;
  acceleration = Vector(0.0f, 0.0f, 0.0f);
}

GravityWell::GravityWell(std::string id, std::string model, Vector pos,
                         Vector velocity, double mass, float scale) {
  source = "";
  objectType = "gravitywell";
  build(id, model, pos, velocity, mass, scale);
}

GravityWell::~GravityWell() {

}

void GravityWell::gravity(Object *other) {
  if (other->getID() != id) {
    Vector v = pos - other->getPos();
    double r = v.magnitude();
    v = v.normalize();
    other->applyForce(v * ((GRAVCONST * mass * other->getMass()) / (r * r)));
  }
}

void GravityWell::detectCollision(Object *other) {
  done = true;
}

void GravityWell::action() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->resetList();
    while (1) {
      gravity(list->currentElement());
      if (!list->nextElement())
        break;
    }
    list->setCurrent(le);
  }
}
