#include "Program.h"

Program::Program()
{
	prog = 0;
	id = "";
}

Program::Program(std::string id, GLuint vertShader, GLuint fragShader)
{
	this->id = id;
	link(vertShader,fragShader);
}

Program::~Program()
{
	release();
}

std::string Program::getID()
{
	return id;
}

void Program::link(GLuint vertShader, GLuint fragShader)
{
	prog = glCreateProgram();
	glAttachShader(prog,vertShader);
	if(fragShader) glAttachShader(prog,fragShader);
	glLinkProgram(prog);
	int linked=0;
	glGetShaderiv(prog, GL_LINK_STATUS, &linked);
	if (!linked)
	{ // congratulations! the program is linked!
		std::cout<<"[Shaders Linked]"<<std::endl;
	}
	else
	{
		std::cerr<<"[Error: Could not link shaders]"<<std::endl;
	}
}
	
void Program::use()
{
	glUseProgram(prog);
}
	
void Program::release()
{
	int del = 0;
	glGetShaderiv(prog, GL_DELETE_STATUS, &del);
	if(!del)glDeleteProgram(prog);
}
