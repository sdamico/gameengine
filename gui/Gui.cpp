#include "Gui.h"

void Gui::click(std::string id) {
  std::cout << "[Button " << id << " Clicked]" << std::endl;
}

Gui::Gui() {

  //gobj.addElement(new Crosshair("crosshair1", (Vector){0.1f,0.1f,0.0f}, (Vector){-0.1f,-0.1f,0.0f}));

  //gobj.addElement(new Button("b1","Button 1", "button", (Vector){-1.0f,0.75f,0.0f}, (Vector){-0.75f,1.0f,0.0f}, &click));

  //gobj.addElement(new Button("b2","Button 2", "button", (Vector){-0.75f,0.75f,0.0f}, (Vector){-0.50f,1.0f,0.0f}, &click));
  std::cout << "[Starting GUI]" << std::endl;
}

Gui::~Gui() {
  std::cout << "[Ending GUI]" << std::endl;
  gobj.deleteAllElements();
}
void Gui::handle(int mx, int my, int b) {
  gobj.resetList();

  while (1) {
    if (!gobj.currentElement())
      break;
    gobj.currentElement()->checkActivation(mx, my, b);
    if (!gobj.nextElement())
      break;
  }
}
void Gui::render() {
  glPushMatrix();
  glDisable(GL_BLEND);
  glDisable(GL_LIGHTING);
  gobj.resetList();

  while (1) {
    if (!gobj.currentElement())
      break;
    gobj.currentElement()->render();
    if (!gobj.nextElement())
      break;
  }
  glEnable(GL_LIGHTING);
  glEnable(GL_BLEND);
  glPopMatrix();
}
