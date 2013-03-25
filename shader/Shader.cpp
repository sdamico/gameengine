#include "Shader.h"

Shader::Shader() {
  sh = 0;
}

Shader::~Shader() {
  release();
}

Shader::Shader(std::string nid, std::string file, GLuint type) {
  sh = 0;
  if (!load(nid, file, type))
    std::cerr << "[Could not load shader: " << file << "]\n";
}

Shader Shader::operator =(Shader s) {
  sh = s.sh;
  id = s.id;
  return s;
}

std::string Shader::getID() {
  return id;
}

GLuint Shader::getType() {
  return type;
}

GLuint Shader::getShader() {
  return sh;
}

bool Shader::load(std::string id, std::string file, GLuint type) {
  this->id = id;
  this->type = type;
  sh = glCreateShader(type);

  std::string tempfile, buffer;
  std::ifstream File;
  File.open(file.c_str(), std::ifstream::in);
  if (!File)
    return false;
  while (std::getline(File, buffer))
    tempfile += buffer;
  tempfile += "\0";
  File.close();
  const char * shadertemp = tempfile.c_str();
  glShaderSource(sh, 1, &shadertemp, NULL);
  glCompileShader(sh);
  int res = 0;
  glGetShaderiv(sh, GL_COMPILE_STATUS, &res);
  if (res)
    return true;
  else
    return false;
}

bool Shader::attach(GLuint program) {
  glAttachShader(program, sh);
  return true;
}

bool Shader::release() {
  glDeleteShader(sh);
  return true;
}
