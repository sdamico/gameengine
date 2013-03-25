#ifndef PARTICLE_H
#define PARTICLE_H

#include "../res.h"
#include "../mm/singleton.h"
#include "../texture/texturemgr.h"
#include "../time/time.h"
#include "../camera/Camera.h"
#include "../vector/FVector.h"

struct Particle {
  glRGBA curColor;
  FVector pos;
  bool state;
  int type;
  FVector velocity;
  float scale;
  float curScale;
  float endScale;
  float scalestep;
  glRGBA startColor;
  glRGBA endColor;
  std::string tex;
  Texture *texptr;
  long counter;
  float lifetime;
  float fadestep;
};

class ParticleMgr : public Singleton<ParticleMgr> {
  static const int MAX_PARTICLES = 2048;
  Particle particles[MAX_PARTICLES];

 public:
  int numParticles;

  ParticleMgr();
  ~ParticleMgr();

  //Basic Methods
  void startParticle(int type, glRGBA color, std::string t, float scale,
                     float endScale, long lifetime, Vector ps, Vector v);
  void handle();
  void render();

  //Special Effects
  //Basic explosion
  void startExplosion(std::string t, int numParticles, float scale,
                      float endScale, long lifetime, Vector pos,
                      Vector velocity, float explosionSpeed);
};
#endif

