#ifndef OBJECT_H
#define OBJECT_H
#include "../math/Quaternion.h"
#include "../model/ModelMgr.h"
#include "../shader/ShaderMgr.h"
#include "../time/time.h"
#include "../vector/vector.h"
#include "../model/C3ds.h"

class Object {
 protected:
  std::string id;
  std::string model;
  std::string objectType;
  std::string factionID;
  //std::string shader;
  Quaternion q;

  Vector velocity;
  Vector acceleration;

  Vector omega;
  Vector alpha;
  double momentOfInertia;

  float size;
  float scale;
  Vector pos;
  double mass;
  Vector up, right, look;

  std::string source;

  std::string collisionID;
  long lastCollision;

 public:

  bool done;
  //texture *tex;
  Object();
  Object(std::string id, std::string model, Vector pos, Vector velocity,
         double mass, float scale);
  void build(std::string id, std::string model, Vector pos, Vector velocity,
             double mass, float scale);
  virtual ~Object();
  void renderMiniAtOrigin();
  void renderAtOrigin();
  void render();
  virtual void extraRender();
  void rotateAxis(Vector axis, double angle);
  void move();
  void accelerate();
  void applyForce(Vector force);
  void angularMove();
  void angularAccelerate();
  void applyTorque(Vector t);

  bool detectCollision(Object *other);
  Vector detectCollision(Vector x1, Vector x2);
  virtual void handleCollision(Object *other);
  virtual void action();
  std::string getID();
  std::string getObjectType();
  std::string getFactionID();
  Vector getPos();
  Vector getVelocity();
  Vector getOmega();
  double getMomentOfInertia();
  double getSphereRadius();
  double getMass();
  void getMatrix(double *m);
  Vector getUp();
  Vector getRight();
  Vector getLook();
  std::string getSource();
  Quaternion getQuaternion();
};
#endif

