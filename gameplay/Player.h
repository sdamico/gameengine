#ifndef PLAYER_H_
#define PLAYER_H_
#include "../camera/Camera.h"
#include "../font/font.h"
#include "Ship.h"
#include "TargetingSystem.h"
#include "../physics/objectmgr.h"
#include "Missile.h"
#include "Radar.h"
#include "PlayerStatusIndicator.h"
#include "WeaponDisplay.h"

class Player : public Ship {
  bool syncCamera;
  Quaternion view;
  bool tracking;
  unsigned int hits;
  bool beamOn;
  Radar *radar;
  PlayerStatusIndicator *playerStatus;
  WeaponDisplay *weaponDisplay;
 public:
  Player();
  Player(std::string id, std::string factionID, std::string model, Vector pos,
         Vector velocity, Quaternion q, double mass, float scale);
  std::string getTarget();
  std::string getTargetID();
  void extraRender();
  void renderHUD();
  void nextTarget();
  void prevTarget();
  void targetNearest();
  void targetNearestEnemy();
  void targetNearestAlly();
  void targetNearestMissile();
  void fireMissile();
  void activateBeam();
  void toggleRadarZoom();
  void lookByAxisAngle(Vector axis, double angle);
  void action();
  void handleCollision(Object *other);
  void toggleTracking();
  bool isTracking();
  unsigned int getHits();
  double getBeamEnergy();
  double getBeamHeat();
  virtual ~Player();
};

#endif /*PLAYER_H_*/
