#include "TargetingSystem.h"
#include "Ship.h"

TargetingSystem::TargetingSystem() {
  currentTarget = "";
}

TargetingSystem::TargetingSystem(Object *parent) {
  this->parent = parent;
  currentTarget = "";
}

TargetingSystem::~TargetingSystem() {
}

void TargetingSystem::nextTarget() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->find(currentTarget);

    if (!list->nextElement())
      list->resetList();

    currentTarget = list->currentElement()->getID();
    list->setCurrent(le);
  }
}

void TargetingSystem::prevTarget() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->find(currentTarget);

    if (!list->prevElement())
      list->resetListToLast();

    currentTarget = list->currentElement()->getID();
    list->setCurrent(le);
  }
}

Object *TargetingSystem::getTarget() {
  List<Object> *list = ObjectMgr::get().getList();
  ListElement<Object> *le = list->getCurrent();
  Object *targ = list->find(currentTarget);
  list->setCurrent(le);
  return targ;
}

Object *TargetingSystem::getParent() {
  return parent;
}

std::string TargetingSystem::getTargetID() {
  return currentTarget;
}

void TargetingSystem::targetNearest() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->resetList();

    Object *o = NULL;
    double dist = 0;
    while (1) {
      //if(obj!=objectList->currentElement() && source!=objectList->currentElement()){
      if (parent->getID() != list->currentElement()->getID()) {
        double newDist = (list->currentElement()->getPos() - parent->getPos())
            .magnitude();
        if (newDist < dist || !dist) {
          dist = newDist;
          o = list->currentElement();
        }
      }
      if (!list->nextElement())
        break;
    }

    if (o)
      currentTarget = o->getID();

    list->setCurrent(le);
  }
}

void TargetingSystem::targetNearestEnemy() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->resetList();

    Object *o = NULL;
    double dist = 0;
    while (1) {
      //if(obj!=objectList->currentElement() && source!=objectList->currentElement()){
      if (parent->getID() != list->currentElement()->getID()
          && list->currentElement()->getObjectType() != "missile"
          && list->currentElement()->getObjectType() != "object"
          && list->currentElement()->getObjectType() != "gravitywell"
          && (list->currentElement()->getFactionID() == ""
              || parent->getFactionID()
                  != list->currentElement()->getFactionID())) {
        double newDist = (list->currentElement()->getPos() - parent->getPos())
            .magnitude();
        if (newDist < dist || !dist) {
          dist = newDist;
          o = list->currentElement();
        }
      }
      if (!list->nextElement())
        break;
    }

    if (o)
      currentTarget = o->getID();

    list->setCurrent(le);
  }
}

void TargetingSystem::targetNearestAlly() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->resetList();

    Object *o = NULL;
    double dist = 0;
    while (1) {
      //if(obj!=objectList->currentElement() && source!=objectList->currentElement()){
      if (parent->getID() != list->currentElement()->getID()
          && list->currentElement()->getObjectType() != "missile"
          && list->currentElement()->getObjectType() != "object"
          && list->currentElement()->getObjectType() != "gravitywell"
          && parent->getFactionID() == list->currentElement()->getFactionID()) {
        double newDist = (list->currentElement()->getPos() - parent->getPos())
            .magnitude();
        if (newDist < dist || !dist) {
          dist = newDist;
          o = list->currentElement();
        }
      }
      if (!list->nextElement())
        break;
    }

    if (o)
      currentTarget = o->getID();

    list->setCurrent(le);
  }
}

void TargetingSystem::targetNearestMissile() {
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->resetList();

    Object *o = NULL;
    double dist = 0;
    while (1) {
      //if(obj!=objectList->currentElement() && source!=objectList->currentElement()){
      if (parent->getID() != list->currentElement()->getID()
          && list->currentElement()->getObjectType() == "missile") {
        double newDist = (list->currentElement()->getPos() - parent->getPos())
            .magnitude();
        if (newDist < dist || !dist) {
          dist = newDist;
          o = list->currentElement();
        }
      }
      if (!list->nextElement())
        break;
    }

    if (o)
      currentTarget = o->getID();

    list->setCurrent(le);
  }
}

void TargetingSystem::drawBox(Object *o, glRGBA color, double *m) {
  if (o && Camera::get().sphereInFrustum(o->getPos(), o->getSphereRadius())
      && m) {
    glPushMatrix();
    glLoadIdentity();
    Camera::get().setPerspective();

    Vector v = o->getPos() - Camera::get().getPos();
    double sizeDecrease = 4.0f / (5.0f * v.magnitude());
    v = v.normalize();
    v = v / 0.8f;

    //glTranslatef(Camera::get().getPos().x,Camera::get().getPos().y,Camera::get().getPos().z);

    glTranslatef(v.x, v.y, v.z);
    glMultMatrixd(m);
    //set a minimum scale for the box, so that it's always visible
    if (o->getSphereRadius() * 0.5f * sizeDecrease > 0.01f)
      glScalef(o->getSphereRadius() * 0.5f * sizeDecrease,
               o->getSphereRadius() * 0.5f * sizeDecrease,
               o->getSphereRadius() * 0.5f * sizeDecrease);
    else
      glScalef(0.01f, 0.01f, 0.01f);

    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    //glLoadIdentity();
    glBegin(GL_LINE_STRIP);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnd();

    glPopMatrix();
  }
}

void TargetingSystem::drawTargetingBoxes() {
  double m[16];
  Camera::get().getMatrix(m);
  List<Object> *list = ObjectMgr::get().getList();
  if (list) {
    ListElement<Object> *le = list->getCurrent();
    list->resetList();
    glPointSize(3.0f);
    while (1) {
      Object *obj = list->currentElement();
      if (obj->getID() == currentTarget)
        drawBox(obj, (glRGBA) {0.0f,1.0f,0.0f,1.0f}, m);
      else if (!(obj->getObjectType() == "missile"
          || obj->getObjectType() == "gravitywell"
          || obj->getObjectType() == "object")) {
        if (obj->getFactionID() == parent->getFactionID())
          drawBox(obj, (glRGBA) {1.0f,1.0f,1.0f,1.0f}, m);
        else
          drawBox(obj, (glRGBA) {1.0f,0.0f,0.0f,1.0f}, m);
      }
      if (!list->nextElement())
        break;
    }

    list->setCurrent(le);
  }
}

void TargetingSystem::render() {
  List<Object> *list = ObjectMgr::get().getList();

  glDisable(GL_LIGHTING);
  //glDisable(GL_COLOR_MATERIAL);
  glDisable(GL_TEXTURE_2D);
  glMaterialfv(GL_FRONT, GL_EMISSION, (const float[4]) {1.0f,1.0f,1.0f,1.25f});
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  //glDisable(GL_BLEND);

  double m[16];
  Camera::get().getMatrix(m);

  drawTargetingBoxes();

  glPushMatrix();

  glLoadIdentity();
  Camera::get().setPerspective();

  glTranslatef(Camera::get().look.x / 0.8f, Camera::get().look.y / 0.8f,
               Camera::get().look.z / 0.8f);
  glTranslatef(Camera::get().up.x * -0.55f, Camera::get().up.y * -0.55f,
               Camera::get().up.z * -0.55f);
  glTranslatef(Camera::get().right.x * 0.60f, Camera::get().right.y * 0.60f,
               Camera::get().right.z * 0.60f);
  glScalef(0.16f, 0.16f, 0.16f);

  glPushMatrix();

  glMultMatrixd(m);
  glTranslatef(-0.4f, 0.5f, 1.0f);
  glScalef(1.2f, 1.2f, 1.0f);
  glBegin(GL_QUADS);
  glColor4f(0.0f, 0.1f, 0.5f, 0.5f);
  glVertex3f(1.0f, -1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 0.0f);
  glVertex3f(-1.0f, 1.0f, 0.0f);
  glVertex3f(1.0f, 1.0f, 0.0f);
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  glEnd();
  glPopMatrix();

  //glTranslatef(-Camera::get().look.x*10.0f,-Camera::get().look.y*10.0f,-Camera::get().look.z*1.0f);

  Object *t = NULL;
  if (list->find(currentTarget)) {
    t = list->currentElement();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    t->renderMiniAtOrigin();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }
  glPopMatrix();
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glColor4f(0.1f, 1.0f, 0.0f, 1.0f);
  if (t) {
    glRasterPos3f(0.4f, -0.55f, -0.5f);
    FontLib::get().glPrint("%s", t->getID().c_str());
    glRasterPos3f(0.4f, -0.58f, -0.5f);
    FontLib::get().glPrint("Faction: %s", t->getFactionID().c_str());
    if (t->getObjectType() == "ship" || t->getObjectType() == "player") {
      glRasterPos3f(0.4f, -0.61f, -0.5f);
      FontLib::get().glPrint("Hull: %0.2f", ((Ship*) t)->getHull());
    }
    Vector relVelocity = t->getVelocity() - getParent()->getVelocity();
    glRasterPos3f(0.4f, -0.86f, -0.5f);
    FontLib::get().glPrint("Relative Velocity:");
    glRasterPos3f(0.4f, -0.89f, -0.5f);
    FontLib::get().glPrint("<%0.2f, %0.2f, %0.2f>", relVelocity.x,
                           relVelocity.y, relVelocity.z);
    Vector toTarget = t->getPos() - getParent()->getPos();
    glRasterPos3f(0.4f, -0.92f, -0.5f);
    FontLib::get().glPrint("To Target:");
    glRasterPos3f(0.4f, -0.95f, -0.5f);
    FontLib::get().glPrint("<%0.2f, %0.2f, %0.2f>", toTarget.x, toTarget.y,
                           toTarget.z);
    glRasterPos3f(0.4f, -0.98f, -0.5f);
    if (t->getObjectType() == "ship" || t->getObjectType() == "player") {
      FontLib::get().glPrint("Current Target: %s",
                             ((Ship*) t)->getTargetID().c_str());
    } else if (t->getObjectType() == "missile") {
      FontLib::get().glPrint("Current Target: %s",
                             ((Missile*) t)->getTargetID().c_str());
    }
  } else {
    glRasterPos3f(0.4f, -0.55f, -0.5f);
    FontLib::get().glPrint("No Target Selected");
  }
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glEnable(GL_BLEND);
  //glDepthMask(GL_TRUE);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);

}

