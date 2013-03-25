#ifndef RAWTRIANGLES_H_
#define RAWTRIANGLES_H_

#include "Model.h"

class RawTriangles : public Model {
  FVector *vertex;
  FVector *normal;
  int numVerts;

 public:
  RawTriangles();
  RawTriangles(std::string id, std::string file, int vert, float scale);
  ~RawTriangles();
  bool load(std::string id, std::string file, int vert, float scale);
  void release();
  void render();
};

#endif /*RAWTRIANGLES_H_*/
