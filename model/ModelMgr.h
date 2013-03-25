#ifndef MODELMGR_H_
#define MODELMGR_H_

#include "../mm/list.h"
#include "../mm/singleton.h"
#include "../camera/Camera.h"
#include "Model.h"
class ModelMgr : public Singleton<ModelMgr> {
  List<Model> mlist;
 public:
  ModelMgr();
  virtual ~ModelMgr();
  void load(Model *m);
  void unload(std::string id);
  void render(std::string id, Vector pos);
  void render(std::string id);
  Model *find(std::string id);
};

#endif /*MODELMGR_H_*/
