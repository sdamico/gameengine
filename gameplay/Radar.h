#ifndef RADAR_H_
#define RADAR_H_

#include "../physics/objectmgr.h"
#include "../texture/texturemgr.h"
#include "TargetingSystem.h"

class Radar {
  double range;
  std::string tex;

  TargetingSystem *targeting;
  bool zoom;
 public:
  Radar();
  Radar(TargetingSystem *targeting, std::string texture);
  virtual ~Radar();
  void toggleZoom();
  void render();
};

#endif /*RADAR_H_*/
