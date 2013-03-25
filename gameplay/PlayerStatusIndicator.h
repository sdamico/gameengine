#ifndef PLAYERSTATUSINDICATOR_H_
#define PLAYERSTATUSINDICATOR_H_

#include "../physics/objectmgr.h"
#include "../texture/texturemgr.h"

class PlayerStatusIndicator {
  double range;
  std::string tex;
  Object *parent;
 public:
  PlayerStatusIndicator();
  PlayerStatusIndicator(Object *parent, std::string tex);
  virtual ~PlayerStatusIndicator();
  void render();
  void getParent();
};

#endif /*PLAYERSTATUSINDICATOR_H_*/
