#include "Quaternion.h"

Quaternion::Quaternion() {
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
  w = 1.0f;
}
Quaternion::Quaternion(double x, double y, double z, double w) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}
Quaternion::~Quaternion() {
}

void Quaternion::createFromAxisAngle(double nx, double ny, double nz,
                                     double degrees) {
  double angle = double(DEG2RAD(degrees));
  double result = (double) sin(angle / 2.0f);
  w = (double) cos(angle / 2.0f);
  x = nx * result;
  y = ny * result;
  z = nz * result;

}

void Quaternion::createFromAxisAngle(Vector axis, double degrees) {
  double angle = double(DEG2RAD(degrees));
  double result = (double) sin(angle / 2.0f);
  w = (double) cos(angle / 2.0f);
  x = axis.x * result;
  y = axis.y * result;
  z = axis.z * result;
}

void Quaternion::createMatrix(double *matrix) {
  if (!matrix)
    return;
  matrix[0] = 1.0f - 2.0f * (y * y + z * z);
  matrix[1] = 2.0f * (x * y + z * w);
  matrix[2] = 2.0f * (x * z - y * w);
  matrix[3] = 0.0f;
  // Second row
  matrix[4] = 2.0f * (x * y - z * w);
  matrix[5] = 1.0f - 2.0f * (x * x + z * z);
  matrix[6] = 2.0f * (z * y + x * w);
  matrix[7] = 0.0f;
  // Third row
  matrix[8] = 2.0f * (x * z + y * w);
  matrix[9] = 2.0f * (y * z - x * w);
  matrix[10] = 1.0f - 2.0f * (x * x + y * y);
  matrix[11] = 0.0f;
  // Fourth row
  matrix[12] = 0;
  matrix[13] = 0;
  matrix[14] = 0;
  matrix[15] = 1.0f;

}

void Quaternion::createMatrix(float *matrix) {
  if (!matrix)
    return;
  matrix[0] = 1.0f - 2.0f * (y * y + z * z);
  matrix[1] = 2.0f * (x * y + z * w);
  matrix[2] = 2.0f * (x * z - y * w);
  matrix[3] = 0.0f;
  // Second row
  matrix[4] = 2.0f * (x * y - z * w);
  matrix[5] = 1.0f - 2.0f * (x * x + z * z);
  matrix[6] = 2.0f * (z * y + x * w);
  matrix[7] = 0.0f;
  // Third row
  matrix[8] = 2.0f * (x * z + y * w);
  matrix[9] = 2.0f * (y * z - x * w);
  matrix[10] = 1.0f - 2.0f * (x * x + y * y);
  matrix[11] = 0.0f;
  // Fourth row
  matrix[12] = 0;
  matrix[13] = 0;
  matrix[14] = 0;
  matrix[15] = 1.0f;

}

Quaternion Quaternion::operator*(Quaternion q) {
  Quaternion r;

  r.w = w * q.w - x * q.x - y * q.y - z * q.z;
  r.x = w * q.x + x * q.w + y * q.z - z * q.y;
  r.y = w * q.y + y * q.w + z * q.x - x * q.z;
  r.z = w * q.z + z * q.w + x * q.y - y * q.x;

  return (r);
}
Quaternion Quaternion::conjugate() {
  Quaternion q;
  q.x = -x;
  q.y = -y;
  q.z = -z;
  q.w = w;
  return q;
}
Quaternion Quaternion::normalize() {
  double magnitude = sqrt(x * x + y * y + z * z + w * w);
  if (magnitude > 0.0f) {
    Quaternion q;
    q.x = x / magnitude;
    q.y = y / magnitude;
    q.z = z / magnitude;
    q.w = w / magnitude;
    return q;
  } else
    return *this;
}

