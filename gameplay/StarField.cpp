#include "StarField.h"

StarField::StarField() {
  m = NULL;
}

StarField::~StarField() {
}

StarField::StarField(std::string model) {
  m = ModelMgr::get().find(model);
}

void StarField::Render() {
  glPushMatrix();
  glLoadIdentity();
  Camera::get().setPerspective();
  if (m)
    m->render();
}
