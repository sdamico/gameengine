#ifndef SHADER_H_
#define SHADER_H_

#include "../res.h"

class Shader
{
	GLuint sh;
	GLuint type;
	std::string id;
public:

	
	Shader();
	virtual ~Shader();
	Shader(std::string nid, std::string file, GLuint type);
	Shader operator = (Shader s);
	std::string getID();
	GLuint getShader();
	GLuint getType();
	bool load(std::string id, std::string file, GLuint type);
	bool attach(GLuint program);
	bool release();
};

#endif /*SHADER_H_*/
