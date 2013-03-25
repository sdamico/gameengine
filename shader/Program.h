#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "Shader.h"

class Program
{
	GLuint prog;
	std::string id;
public:
	Program();
	Program(std::string id, GLuint vertShader, GLuint fragShader);
	virtual ~Program();
	std::string getID();
	void link(GLuint vertShader, GLuint fragShader);
	void use();
	void release();
};

#endif /*PROGRAM_H_*/
