#ifndef TEXTURE_H
#define TEXTURE_H

#include "../vector/vector.h"
#include "../tga/tga.h"

//Texture Class
class Texture
{
	//OpenGL texture storage variable
	unsigned int tex;
	
	//Width, height of texture
	int width, height;
	
	std::string id;
	
	public: 
	
	//Blank default constructor
	Texture();
	
	//Destructor 
	~Texture();
	
	//Constructor (loads)
	Texture(std::string nid, std::string file);
	
	//Assignment operator
	void operator = (Texture p);
	
	//Returns id
	std::string getID();
	
	//Load texture from a file
	bool load(std::string id, std::string file);
	
	//Bind texture
	void bind();
	
	//Release
	void release();
	
};
#endif

