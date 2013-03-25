/*
 * Scenario.cpp
 *
 *  Created on: Sep 9, 2008
 *      Author: sam
 */

#include "Scenario.h"

Scenario::Scenario() {
  id = "";
}

Scenario::Scenario(std::string id, std::string file) {
  this->id = id;
  load(file);
}

Scenario::~Scenario() {

}

bool Scenario::load(std::string file) {
  std::ifstream input(file.c_str());

  if (!input.is_open())
    return false;

  std::string className;
  std::string id;

  while (!input.eof()) {
    input >> className >> id;

    if (className == "C3ds") {
      std::string fileName;
      std::string shaderName;
      double scale;
      input >> fileName >> shaderName >> scale;
      ModelMgr::get().load(new C3ds(id, fileName, shaderName, scale));
    }

    if (className == "Faction") {
      std::string description;
      input >> description;
      FactionMgr::get().add(new Faction(id, description));
    }

    if (className == "Ship") {
      std::string faction, model;
      Vector pos, velocity;
      double mass, scale;
      input >> faction >> model >> pos.x >> pos.y >> pos.z >> velocity.x
          >> velocity.y >> velocity.z >> mass >> scale;
      ObjectMgr::get().add(
          new Ship(id, faction, model, pos, velocity, mass, scale));
    }

    if (className == "Player") {
      std::string faction, model;
      Vector pos, velocity;
      double mass, scale;
      input >> faction >> model >> pos.x >> pos.y >> pos.z >> velocity.x
          >> velocity.y >> velocity.z >> mass >> scale;
      ObjectMgr::get().add(
          new Player(id, faction, model, pos, velocity,
                     Camera::get().getQuaternion(), mass, scale));
    }

    if (className == "GravityWell") {
      std::string model;
      Vector pos, velocity;
      double mass, scale;
      input >> model >> pos.x >> pos.y >> pos.z >> velocity.x >> velocity.y
          >> velocity.z >> mass >> scale;
      ObjectMgr::get().add(
          new GravityWell(id, model, pos, velocity, mass, scale));
    }
  }
  return true;
}

std::string Scenario::getID() {
  return id;
}
