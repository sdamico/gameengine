#include "texture.h"

//Blank default constructor
Texture::Texture()
{
}

//Constructor
Texture::Texture(std::string id, std::string file)
{
	load(id,file);
}

//Destructor
Texture::~Texture()
{
	std::cout<<"[Unloading Texture: "<<id<<"]"<<std::endl;

	release();
}

//Get Texture ID
std::string Texture::getID()
{
	return id;
}

//Load Texture
bool Texture::load(std::string nid, std::string file)
{
	//New Image image
	CTargaImage *image=new CTargaImage;
	
	//Load image
 	if(!image->load((char *)file.c_str())) return false;
 	
 	//Generate a GL texture
	glGenTextures(1, &tex);
	
	//Bind the GL Texture
	glBindTexture(GL_TEXTURE_2D, tex);
	
	//Set GL texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	//Build OpenGL texture from image
	//if RGBA
	if(image->getImageFormat()==IMAGE_RGBA){	
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->getWidth(), image->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image->getImage());
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image->getWidth(),image->getHeight(), GL_RGBA, GL_UNSIGNED_BYTE, image->getImage());
	}
	
	//RGB
	if(image->getImageFormat()==IMAGE_RGB){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->getWidth(), image->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image->getImage());
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image->getWidth(),image->getHeight(), GL_RGB, GL_UNSIGNED_BYTE, image->getImage());
	}
	
	//If there is luminance
	if(image->getImageFormat()==IMAGE_LUMINANCE)
	{
		//Set Luminance attribute
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_LUMINANCE, image->getWidth(),image->getHeight(), GL_LUMINANCE, GL_UNSIGNED_BYTE, image->getImage());
	}
	
	//Set width, height
	width=image->getWidth();
	height=image->getHeight();
	
	//Release stored image
	image->release();
	
	//Set identifier
	id=nid;
	
	return true;
}

//Assignment operator
void Texture::operator = (Texture p)
{
	//Set attributes to be the same
	tex=p.tex;
	width=p.width;
	height=p.height;
	id=p.id;
}

//Bind texture to texture coordinates
void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, tex);
}

//Release texture
void Texture::release() 
{
	//Delete texture from OpenGL
	glDeleteTextures(1, &tex); 
}
