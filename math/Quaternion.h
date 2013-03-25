#ifndef _QUATERNION_H_
#define _QUATERNION_H_
#include "../vector/vector.h"

class Quaternion {
 public:
  double x, y, z, w;
  Quaternion();
  Quaternion(double x, double y, double z, double w);
  void createMatrix(double *matrix);
  void createMatrix(float *matrix);
  Quaternion conjugate();
  void createFromAxisAngle(double nx, double ny, double nz, double degrees);
  void createFromAxisAngle(Vector axis, double degrees);
  Quaternion normalize();
  Quaternion operator*(Quaternion q);
  virtual ~Quaternion();
};

#endif //_QUATERNION_H_
