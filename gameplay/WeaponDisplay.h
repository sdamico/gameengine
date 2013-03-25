/*
 * WeaponDisplay.h
 *
 *  Created on: Sep 8, 2008
 *      Author: sam
 */

#ifndef WEAPONDISPLAY_H_
#define WEAPONDISPLAY_H_

#include "WeaponLauncher.h"
#include "../camera/Camera.h"
#include "../font/font.h"

class WeaponDisplay {
  std::string tex;
  std::string crosshairTex;
  WeaponLauncher *curLauncher;
  Object *parent;

 public:
  WeaponDisplay();
  WeaponDisplay(Object *parent, std::string texture,
                std::string crosshairTexture);
  virtual ~WeaponDisplay();
  void setCurrentWeaponLauncher(WeaponLauncher *launcher);
  void render();
};

#endif /* WEAPONDISPLAY_H_ */
