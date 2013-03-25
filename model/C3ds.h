#ifndef C3DS_H_
#define C3DS_H_

#include "../res.h"
#include "Model.h"
#include "../texture/texturemgr.h"
#include "../shader/ShaderMgr.h"
#include "../math/Quaternion.h"

struct ChunkInfo {
  unsigned short ID;
  int Size;
};

class C3ds : public Model {
  GLuint *buffer;

  int nMesh;
  int nMatl;
  FVector *vertex;
  FVector *normal;
  FVector *fnormal;
  UVTexCoord *texcoord;
  float TexCoordUScale;
  float TexCoordVScale;
  Face *face;
  int numVerts, numFaces, numTexCoords;
  glRGBA color;
  glRGBA ambientColor, diffuseColor, specColor;
  GLubyte shininess, transparency;
  int texSmooth;
  std::string texture;
  int fileSize;
  unsigned char *data;
  ChunkInfo getChunkInfo(int Offset);
  int countParts(int DataLen);

  //Warning - do not use
  bool segInTriangle(FVector p, FVector d, FVector* v);

  void calcNormals();
  std::string shader;
  bool buffersSupported;
 public:
  C3ds();
  C3ds(std::string id, std::string file, std::string shaderProgram,
       float scale);
  ~C3ds();
  bool load(std::string id, std::string file, float scale);
  void setShader(std::string program);
  void release();
  void render();

  //Warning - do not use both intersect functions
  bool intersect(C3ds *other, float scale, float otherScale, FVector separation,
                 Quaternion q1, Quaternion q2);
  FVector intersect(FVector x1, FVector x2, float scale, Quaternion q1);
};

#endif /*C3DS_H_*/
