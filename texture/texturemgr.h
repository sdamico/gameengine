#ifndef TEXTUREMGR_H
#define TEXTUREMGR_H

#include "texture.h"
#include "../mm/list.h"
#include "../mm/singleton.h"

class TextureMgr : public Singleton<TextureMgr> {
  List<Texture> tlist;
 public:
  TextureMgr();
  ~TextureMgr();
  bool load(std::string id, std::string filename);
  void unload(std::string id);
  void use(std::string id);
  Texture *find(std::string id);
};

#endif

