#include "Md2.h"

Md2::Md2() {
}

Md2::~Md2() {
}

bool Md2::load(std::string id, std::string file) {
  std::ifstream fin;
  fin.open(file.c_str(), std::ios::binary);
  if (fin.fail())
    return false;
  fin.read(reinterpret_cast<char*>(&header), sizeof(Md2Header));
  if (header.ident != MD2_IDENT && header.version != MD2_VERSION) {
    fin.close();
    return false;
  }
  //cout<<header.numXYZ<<endl;
  numFrames = header.numFrames;
  numVerts = header.numXYZ;
  numGLcmds = header.numGLcmds;
  verts = new FVector[header.numXYZ * header.numFrames];
  GLcmds = new int[numGLcmds];
  norms = new FVector[header.numXYZ * header.numFrames];
  buffer = new char[numFrames * header.framesize];
  ellipsoid = new FVector[header.numFrames];
  texcoord = new TexCoord[header.numST];

  return true;
}
