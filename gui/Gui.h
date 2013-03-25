#ifndef GUI_H_
#define GUI_H_
#include "../mm/singleton.h"
#include "../font/font.h"
#include "../mm/list.h"
#include "GuiObject.h"
#include "Button.h"
#include "Crosshair.h"

class Gui : public Singleton<Gui> {
  List<GuiObject> gobj;
  static void click(std::string id);
 public:
  Gui();
  virtual ~Gui();
  void addGui();
  void handle(int mx, int my, int b);
  void render();
};

#endif /*GUI_H_*/
