#include "ModelMgr.h"

ModelMgr::ModelMgr() {
  std::cout << "[Starting Model Manager]" << std::endl;
}

ModelMgr::~ModelMgr() {
  std::cout << "[Ending Model Manager]" << std::endl;
}
void ModelMgr::load(Model *m) {
  mlist.addElement(m);

}
void ModelMgr::unload(std::string id) {
  mlist.deleteElement(id);
}
void ModelMgr::render(std::string id, Vector pos) {
  if (mlist.find(id)) {

    if (Camera::get().sphereInFrustum(
        pos, mlist.currentElement()->getSphereRadius())) {

      glPushMatrix();
      glTranslatef(pos.x, pos.y, pos.z);
      mlist.currentElement()->render();
      glPopMatrix();
    }

  }
}
void ModelMgr::render(std::string id) {
  if (mlist.find(id)) {

    mlist.currentElement()->render();

  }
}
Model *ModelMgr::find(std::string id) {
  return mlist.find(id);
}
