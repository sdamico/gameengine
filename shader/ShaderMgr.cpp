#include "ShaderMgr.h"

ShaderMgr::ShaderMgr()
{
	std::cout<<"[Starting Shader Manager]"<<std::endl;	
	glewInit();
	if (glewIsSupported("GL_VERSION_2_0"))
	{
		std::cout<<"[GLSL Supported]\n";
		glEnable(GL_VERTEX_SHADER);
		glEnable(GL_FRAGMENT_SHADER);
		supported = true;
	} else {
		std::cout<<"[No GLSL support]\n";
		supported = false;
	}
	enabled = true;
	
}

ShaderMgr::~ShaderMgr()
{
	std::cout<<"[Ending Shader Manager]"<<std::endl;
}


bool ShaderMgr::load(std::string id, std::string filename, GLuint type)
{
	if(supported && enabled)
		slist.addElement(new Shader(id,filename,type));
	else std::cerr<<"[Cannot Load Shader \""<<filename<<"\", GLSL Not Supported]"<<std::endl;
	return true;
}

void ShaderMgr::unloadShader(std::string id)
{
	slist.deleteElement(id);
}

void ShaderMgr::unloadProgram(std::string id)
{
	plist.deleteElement(id);
}

void ShaderMgr::useShader(std::string id, GLuint program)
{
	if(supported && enabled)
		if(slist.find(id))
		{
			slist.currentElement()->attach(program);
		}
}

void ShaderMgr::useProgram(std::string id)
{
	if(supported && enabled)
		if(plist.find(id))
		{
			plist.currentElement()->use();
		} 
}

void ShaderMgr::linkProgram(std::string program, std::string vertShader, std::string fragShader)
{
	if(supported && enabled)
	{
		Shader *v = find(vertShader);
		Shader *f = find(fragShader);
		if(v && f)
		{
			if(v->getType()==GL_VERTEX_SHADER && f->getType()==GL_FRAGMENT_SHADER)
			{
				plist.addElement(new Program(program,v->getShader(),f->getShader()));
			}
		} else if(v)
		{
			if(v->getType()==GL_VERTEX_SHADER)
			{
				plist.addElement(new Program(program,v->getShader(),0));
			}
		}
	}
}

void ShaderMgr::enable()
{
	enabled = true;
}

void ShaderMgr::disable()
{
	enabled = false;
}

void ShaderMgr::useNone()
{
	if(supported && enabled)
		glUseProgram(0);
}

Shader *ShaderMgr::find(std::string id)
{
	if(slist.find(id))
	{
		return slist.currentElement();
	}
	return false;
}
