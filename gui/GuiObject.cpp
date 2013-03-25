#include "GuiObject.h"
#include "../engine.h"

GuiObject::GuiObject() {

}

GuiObject::~GuiObject() {
}

GuiObject::GuiObject(std::string ident, std::string contents,
                     std::string texture, Vector p, Vector d,
                     void (*callbk)(std::string)) {
  init(ident, contents, texture, p, d, callbk);
}

void GuiObject::init(std::string ident, std::string contents,
                     std::string texture, Vector p, Vector d,
                     void (*callbk)(std::string)) {
  texName = texture;
  tex = NULL;
  tex = TextureMgr::get().find(texture);
  id = ident;
  text = contents;
  posTopLeft = p;
  posBottomRight = d;
  onActivate = callbk;
  clicked = false;
  clickTimer = SDL_GetTicks();
}

void GuiObject::checkActivation(int mx, int my, int b) {
  int swidth = GraphicsEngine::get().getWidth();
  int sheight = GraphicsEngine::get().getHeight();

  if (onActivate) {
    if (SDL_GetTicks() - clickTimer > 250
        && ((posTopLeft.x + 1.0f) / 2.0f) * swidth <= mx
        && (sheight - ((posTopLeft.y + 1.0f) / 2.0f) * sheight) >= my
        && ((posBottomRight.x + 1.0f) / 2.0f) * swidth >= mx
        && (sheight - ((posBottomRight.y + 1.0f) / 2.0f) * sheight) <= my
        && b == 1) {
      onActivate(id);
      clicked = true;
      clickTimer = SDL_GetTicks();
    }
  }
}

std::string GuiObject::getID() {
  return id;
}

void GuiObject::render() {

}
