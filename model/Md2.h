#ifndef MD2_H_
#define MD2_H_
#include "../res.h"
#include "Model.h"

#define MD2_IDENT                (('2'<<24) + ('P'<<16) + ('D'<<8) + 'I')

#define MD2_VERSION              8

struct TexCoord {
  float s, t;
};

struct TexCoordIndex {
  short u, v;
};

struct Md2Header {
  int ident;	//Magic Number "IPD2"
  int version;  //Version of MD2 Format
  int skinwidth;  //Width of Texture
  int skinheight;  //Height of Texture
  int framesize;  //Number of bytes per frame
  int numSkins;  //Number of Textures
  int numXYZ;  //Number of Vertices
  int numST;  //Number of Texture Coordinates
  int numTris;  //Number of Triangles
  int numGLcmds;  //Number of OpenGL commands
  int numFrames;  //Number of Frames
  int offsetSkins;  //offset to skin names
  int offsetST;  //offset to s-t texture coordinates
  int offsetTris;  //offset to Triangles
  int offsetFrames;  //offset to frame data
  int offsetGLcmds;  //offset to opengl commands
  int offsetEnd;  //offset to end of file
};

class Md2 : public Model {
  int numVerts;
  int numFrames;
  int numGLcmds;
  int *GLcmds;
  char *buffer;
  FVector *verts;
  TexCoord *texcoord;
  TexCoordIndex *texcoordPtr;
  FVector *norms;
  FVector *ellipsoid;
  Md2Header header;
 public:
  Md2();
  virtual ~Md2();
  bool load(std::string id, std::string file);
};

#endif /*MD2_H_*/
