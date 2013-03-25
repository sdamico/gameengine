#include "Camera.h"

//Constructor
Camera::Camera() {
  //Set initial values
  pos.x = 0.0f;
  pos.y = 0.0f;
  pos.z = 0.0f;
  right = Vector();
  up = Vector();
  look = Vector();
  Quaternion temp;
  q.createFromAxisAngle(look.x, look.y, look.z, 0.0f);
  temp.createFromAxisAngle(up.x, up.y, up.z, 0.0f);
  q = temp * q;
  temp.createFromAxisAngle(right.x, right.y, right.z, 0.0f);
  q = temp * q;
  std::cout << "[Starting Camera]" << std::endl;
}

//Accelerate
void Camera::accelerate(Vector a) {
  //DV=at
  velocity += a * GlobalTime::get().frameSec;
}

//Rotate around an axis
void Camera::rotateAxis(Vector axis, float angle) {
  Quaternion rotate;
  //create quaternion from axis and angle
  //rotate.createFromAxisAngle(axis.x,axis.y,axis.z,(angle/180.0f)*PI);
  rotate.createFromAxisAngle(axis.x, axis.y, axis.z, angle);
  //quaternion multiplication to rotate relative to old rotation
  q = rotate * q;
}

//Rotate camera into position
void Camera::setPerspective() {
  //Create a new matrix

  double m[16];
  q.createMatrix(m);

  //up=0-2, right=4-6, look=8-10
  up.x = m[0];
  up.y = m[1];
  up.z = m[2];
  right.x = m[4];
  right.y = m[5];
  right.z = m[6];
  look.x = m[8];
  look.y = m[9];
  look.z = m[10];

  //Normalize vectors
  up.normalize();
  right.normalize();
  look.normalize();

  //Set rotation
  gluLookAt(0.0f, 0.0f, 0.0f, look.x, look.y, look.z, up.x, up.y, up.z);

}

//Get camera matrix
void Camera::getMatrix(double *m) {
  q.createMatrix(m);
}

//Set camera matrix
void Camera::setQuaternion(Quaternion q) {
  this->q = q;
  //Create a new matrix
  double m[16];
  q.createMatrix(m);

  //up=0-2, right=4-6, look=8-10
  up.x = m[0];
  up.y = m[1];
  up.z = m[2];
  right.x = m[4];
  right.y = m[5];
  right.z = m[6];
  look.x = m[8];
  look.y = m[9];
  look.z = m[10];

  //Normalize vectors
  up.normalize();
  right.normalize();
  look.normalize();
}

//Translate camera into position
void Camera::translate() {
  glTranslated(-pos.x, -pos.y, -pos.z);
}

//Move camera
void Camera::move() {
  //d=rt
  pos += velocity * GlobalTime::get().frameSec;
}

//Calculate view frustum
void Camera::calcFrustum() {
  //Matrices
  float projection[16];
  float modelview[16];
  float mat[16];

  //Get projection and modelview matrices
  glGetFloatv(GL_PROJECTION_MATRIX, projection);
  glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

  //Get projection*modelview matrix (use OpenGL to do so)
  glPushMatrix();
  glLoadMatrixf(projection);
  glMultMatrixf(modelview);
  glGetFloatv(GL_MODELVIEW_MATRIX, mat);
  glPopMatrix();

  //Size of plane
  float size;

  //Calculate all 6 planes that make up the view frustum

  ViewFrustum.planes[0].A = mat[3] - mat[2];
  ViewFrustum.planes[0].B = mat[7] - mat[6];
  ViewFrustum.planes[0].C = mat[11] - mat[10];
  ViewFrustum.planes[0].D = mat[15] - mat[14];

  size = sqrt(
      ViewFrustum.planes[0].A * ViewFrustum.planes[0].A
          + ViewFrustum.planes[0].B * ViewFrustum.planes[0].B
          + ViewFrustum.planes[0].C * ViewFrustum.planes[0].C);

  ViewFrustum.planes[0].A /= size;
  ViewFrustum.planes[0].B /= size;
  ViewFrustum.planes[0].C /= size;
  ViewFrustum.planes[0].D /= size;

  ViewFrustum.planes[1].A = mat[3] + mat[0];
  ViewFrustum.planes[1].B = mat[7] + mat[4];
  ViewFrustum.planes[1].C = mat[11] + mat[8];
  ViewFrustum.planes[1].D = mat[15] + mat[12];

  size = sqrt(
      ViewFrustum.planes[0].A * ViewFrustum.planes[0].A
          + ViewFrustum.planes[0].B * ViewFrustum.planes[0].B
          + ViewFrustum.planes[0].C * ViewFrustum.planes[0].C);

  ViewFrustum.planes[1].A /= size;
  ViewFrustum.planes[1].B /= size;
  ViewFrustum.planes[1].C /= size;
  ViewFrustum.planes[1].D /= size;

  ViewFrustum.planes[2].A = mat[3] + mat[1];
  ViewFrustum.planes[2].B = mat[7] + mat[5];
  ViewFrustum.planes[2].C = mat[11] + mat[9];
  ViewFrustum.planes[2].D = mat[15] + mat[13];

  size = sqrt(
      ViewFrustum.planes[0].A * ViewFrustum.planes[0].A
          + ViewFrustum.planes[0].B * ViewFrustum.planes[0].B
          + ViewFrustum.planes[0].C * ViewFrustum.planes[0].C);

  ViewFrustum.planes[2].A /= size;
  ViewFrustum.planes[2].B /= size;
  ViewFrustum.planes[2].C /= size;
  ViewFrustum.planes[2].D /= size;

  ViewFrustum.planes[3].A = mat[3] - mat[1];
  ViewFrustum.planes[3].B = mat[7] - mat[5];
  ViewFrustum.planes[3].C = mat[11] - mat[9];
  ViewFrustum.planes[3].D = mat[15] - mat[13];

  size = sqrt(
      ViewFrustum.planes[0].A * ViewFrustum.planes[0].A
          + ViewFrustum.planes[0].B * ViewFrustum.planes[0].B
          + ViewFrustum.planes[0].C * ViewFrustum.planes[0].C);

  ViewFrustum.planes[3].A /= size;
  ViewFrustum.planes[3].B /= size;
  ViewFrustum.planes[3].C /= size;
  ViewFrustum.planes[3].D /= size;

  ViewFrustum.planes[4].A = mat[3] - mat[0];
  ViewFrustum.planes[4].B = mat[7] - mat[4];
  ViewFrustum.planes[4].C = mat[11] - mat[8];
  ViewFrustum.planes[4].D = mat[15] - mat[12];

  size = sqrt(
      ViewFrustum.planes[0].A * ViewFrustum.planes[0].A
          + ViewFrustum.planes[0].B * ViewFrustum.planes[0].B
          + ViewFrustum.planes[0].C * ViewFrustum.planes[0].C);

  ViewFrustum.planes[4].A /= size;
  ViewFrustum.planes[4].B /= size;
  ViewFrustum.planes[4].C /= size;
  ViewFrustum.planes[4].D /= size;

  ViewFrustum.planes[5].A = mat[3] + mat[2];
  ViewFrustum.planes[5].B = mat[7] + mat[6];
  ViewFrustum.planes[5].C = mat[11] + mat[10];
  ViewFrustum.planes[5].D = mat[15] + mat[14];

  size = sqrt(
      ViewFrustum.planes[0].A * ViewFrustum.planes[0].A
          + ViewFrustum.planes[0].B * ViewFrustum.planes[0].B
          + ViewFrustum.planes[0].C * ViewFrustum.planes[0].C);

  ViewFrustum.planes[5].A /= size;
  ViewFrustum.planes[5].B /= size;
  ViewFrustum.planes[5].C /= size;
  ViewFrustum.planes[5].D /= size;

}

//Calculate if a point lies in the frustum
bool Camera::pointInFrustum(Vector p) {
  //loop to make sure that all points are positive (IE fit in the frustum)
  for (int i = 0; i < 6; i++) {
    if ((ViewFrustum.planes[i].A * p.x + ViewFrustum.planes[i].B * p.y
        + ViewFrustum.planes[i].C * p.z + ViewFrustum.planes[i].D) < 0)
      return false;
  }
  return true;
}

//Calculate if a sphere is in the frustum
bool Camera::sphereInFrustum(Vector p, float radius) {
  float dist;
  //Loop to make sure that all points are positive
  for (int i = 0; i < 6; i++) {
    dist = ViewFrustum.planes[i].A * p.x + ViewFrustum.planes[i].B * p.y
        + ViewFrustum.planes[i].C * p.z + ViewFrustum.planes[i].D;
    if (dist <= -radius) {
      //sphere is out of the frustum completely
      return false;
    }
  }
  return true;
}

Vector Camera::getPos() {
  return pos;
}

Vector Camera::getVelocity() {
  return velocity;
}

void Camera::setVelocity(Vector v) {
  velocity = v;
}

Quaternion Camera::getQuaternion() {
  return q;
}

void Camera::setPos(Vector p) {
  pos = p;
}

//Destructor
Camera::~Camera() {
  std::cout << "[Ending Camera]" << std::endl;
}
