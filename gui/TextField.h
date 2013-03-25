#ifndef TEXTFIELD_H_
#define TEXTFIELD_H_

#include "GuiObject.h"

class TextField : public GuiObject {
  bool open;
 public:
  TextField();
  TextField(std::string ident, std::string contents, std::string texture,
            Vector p, Vector d, void (*callbk)(std::string));
  virtual ~TextField();
  void toggleOpen();
  void addText();
  void getText();
  void (*onEnter)(std::string);
  void render();
};

#endif /*TEXTFIELD_H_*/
