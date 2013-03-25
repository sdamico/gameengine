#include "Button.h"

Button::Button() {
}

Button::Button(std::string ident, std::string contents, std::string texture,
               Vector p, Vector d, void (*callbk)(std::string)) {
  init(ident, contents, texture, p, d, callbk);
}

Button::~Button() {
}

void Button::render() {
  glPushMatrix();

  if (tex)
    tex->bind();
  if (clicked) {
    glColor4f(1.0f, 0.2f, 0.2f, 1.0f);

    //clicked=false;
    if (SDL_GetTicks() - clickTimer > 250)
      clicked = false;
  } else
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  glBegin(GL_QUADS);
  //glTranslatef(particles[i].x,particles[i].y,0.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex2f(posBottomRight.x, posTopLeft.y);
  glTexCoord2f(0.0f, 0.0f);
  glVertex2f(posTopLeft.x, posTopLeft.y);

  glTexCoord2f(0.0f, 1.0f);
  glVertex2f(posTopLeft.x, posBottomRight.y);
  glTexCoord2f(1.0f, 1.0f);
  glVertex2f(posBottomRight.x, posBottomRight.y);

  glEnd();
  glRasterPos2f(posTopLeft.x + 0.05f, posTopLeft.y + 0.1f);
  FontLib::get().glPrint("%s", text.c_str());

  glPopMatrix();
}
