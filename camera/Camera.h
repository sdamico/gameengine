#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "../res.h"
#include "../mm/singleton.h"
#include "../vector/vector.h"
#include "../math/Quaternion.h"
#include "../time/time.h"

class Camera : public Singleton<Camera> {

  //Velocity of camera
  Vector velocity;

  //Quaternion of rotation
  Quaternion q;

  float matrix[16];
  struct Frustum {
    struct Plane {
      float A, B, C, D;
    } planes[6];
  } ViewFrustum;

 public:
  //Right, up, and look camera vectors
  Vector right, up, look;

  //Position camera vector
  Vector pos;

  //Constructor
  Camera();

  //Accelerate with Vector A
  void accelerate(Vector a);

  //Rotate around user-defined axis at an angle
  void rotateAxis(Vector axis, float angle);

  //Set camera rotation
  void setPerspective();

  void setQuaternion(Quaternion q);

  //Translate camera to correct position
  void translate();

  //Move camera
  void move();

  //Get camera matrix
  void getMatrix(double *m);

  Quaternion getQuaternion();

  Vector getPos();

  void setPos(Vector p);

  void setVelocity(Vector v);

  Vector getVelocity();

  //Calculate frustum for frustum culling
  void calcFrustum();

  //Determine if a point is in the frustum
  bool pointInFrustum(Vector p);

  //Determine if a sphere is in the frustum
  bool sphereInFrustum(Vector p, float radius);

  //Destructor
  virtual ~Camera();
};

#endif //_CAMERA_H_
