#ifndef SHADERMGR_H_
#define SHADERMGR_H_

#include "Shader.h"
#include "Program.h"
#include "../mm/list.h"
#include "../mm/singleton.h"

class ShaderMgr : public Singleton<ShaderMgr> {
  List<Shader> slist;
  List<Program> plist;
  bool supported;
  bool enabled;
 public:
  ShaderMgr();
  ~ShaderMgr();
  bool load(std::string id, std::string filename, GLuint type);
  void unloadShader(std::string id);
  void unloadProgram(std::string id);
  void useShader(std::string id, GLuint program);
  void useProgram(std::string id);
  void useNone();
  void enable();
  void disable();
  void linkProgram(std::string program, std::string vertShader,
                   std::string fragShader);
  Shader *find(std::string id);
};

#endif /*SHADERMGR_H_*/
