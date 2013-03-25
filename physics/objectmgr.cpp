#include "objectmgr.h"

ObjectMgr::ObjectMgr() {
  std::cout << "[Starting Object Manager]" << std::endl;
  objectList = new List<Object>;
  numObj = 0;
  enableAI();
}

ObjectMgr::~ObjectMgr() {
  std::cout << "[Ending Object Manager]" << std::endl;
  delete objectList;
}

void ObjectMgr::add(Object *obj) {
  objectList->addElement(obj);
}

void ObjectMgr::handle() {
  objectList->resetList();
  Object *o;
  ListElement<Object> *el;
  //cout<<"a\n";
  int i = 0;
  bool br = false;
  while (!br) {
    bool delayDestruction = false;

    if (!objectList->currentElement())
      break;
    o = objectList->currentElement();
    if (!o->done) {
      if (o->getID() != "player") {
        o->accelerate();
        o->angularAccelerate();
        o->move();
        o->angularMove();
        if (aiEnabled)
          o->action();
        Object *hit = detectCollision(o);
        if (hit) {
          delayDestruction = true;
          hit->handleCollision(o);
          o->handleCollision(hit);
        }
      }

    }
    //cout<<i<<" "<<o->id<<endl;
    i++;

    if (o->done && !delayDestruction)
      el = objectList->getCurrent();

    if (!objectList->nextElement()) {
      br = true;

    }

    if (o->done && !delayDestruction) {
      objectList->deleteElement(el);
    }

  }
  //std::cout<<i<<std::endl;
  numObj = i;
}

void ObjectMgr::render() {
  objectList->resetList();
  Object *o;
  //cout<<"a\n";
  int i = 0;
  bool br = false;
  while (!br) {
    if (!objectList->currentElement())
      break;
    o = objectList->currentElement();
    if (!o->done) {
      if (o->getID() != "player") {
        o->render();
      }

    }

    i++;

    if (!objectList->nextElement()) {
      br = true;
    }

  }
  //std::cout<<i<<std::endl;
  numObj = i;

  //do post-render step
  br = false;
  objectList->resetList();
  while (!br) {
    if (!objectList->currentElement())
      break;
    o = objectList->currentElement();
    if (!o->done) {
      if (o->getID() != "player") {
        o->extraRender();
      }

    }

    if (!objectList->nextElement()) {
      br = true;
    }

  }
}

void ObjectMgr::positionPlayer() {
  Object *player = find("player");
  if (player != NULL) {
    player->accelerate();
    player->angularAccelerate();
    player->move();
    player->angularMove();
    player->action();
  }
}

void ObjectMgr::renderPlayer(bool showModel) {
  Object *player = find("player");
  if (player != NULL) {
    player->extraRender();
    if (showModel) {
      glPushMatrix();
      glLoadIdentity();
      double m[16];
      Camera::get().getQuaternion().conjugate().normalize().createMatrix(m);
      glRotatef(180.0f, 1.0f, 1.0f, 0.0f);
      glMultMatrixd(m);

      Vector offset = (Camera::get().up * 1.0f + Camera::get().look * 3.0f)
          * -1;

      glTranslated(offset.x, offset.y, offset.z);
      //glTranslated((Camera::get().look*0.15f-Camera::get().up*0.02f).x,(Camera::get().look*0.15f-Camera::get().up*0.02f).y,(Camera::get().look*0.15f-Camera::get().up*0.02f).z);

      player->renderAtOrigin();
      glPopMatrix();
    }

    Object *hit = detectCollision(player);
    if (hit) {
      hit->handleCollision(player);
      player->handleCollision(hit);
    }
  }
}

Object *ObjectMgr::detectCollision(Object *obj) {
  Object *o;
  ListElement<Object> *el = objectList->getCurrent();
  objectList->resetList();
  while (1) {
    //if(obj!=objectList->currentElement() && source!=objectList->currentElement()){
    if (obj != objectList->currentElement()) {
      if (obj->detectCollision(objectList->currentElement())) {

        o = objectList->currentElement();
        objectList->setCurrent(el);

        return o;
      }

    }
    if (!objectList->nextElement())
      break;
  }
  objectList->setCurrent(el);
  return NULL;
}

//Line-sphere test
Object *ObjectMgr::detectCollision(Vector x1, Vector x2) {
  Object *o;
  ListElement<Object> *el = objectList->getCurrent();
  objectList->resetList();
  while (1) {
    //if(obj!=objectList->currentElement() && source!=objectList->currentElement()){
    Vector v = objectList->currentElement()->detectCollision(x1, x2);
    if (v.magnitude() != 0) {
      o = objectList->currentElement();
      objectList->setCurrent(el);

      return o;
    }
    if (!objectList->nextElement())
      break;
  }
  objectList->setCurrent(el);
  return NULL;
}

List<Object> *ObjectMgr::getList() {
  return objectList;
}

unsigned int ObjectMgr::getNumObj() {
  return numObj;
}

void ObjectMgr::unload(std::string id) {
  objectList->deleteElement(id);
}

Object *ObjectMgr::find(std::string id) {
  //create a new object
  Object *o = NULL;
  //get current position of list
  ListElement<Object> *le = objectList->getCurrent();
  //find object
  o = objectList->find(id);
  //reset list to old position before returning object
  objectList->setCurrent(le);
  return o;
}

void ObjectMgr::enableAI() {
  aiEnabled = true;
}

void ObjectMgr::disableAI() {
  aiEnabled = false;
}
