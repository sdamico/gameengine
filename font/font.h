#include "../res.h"
#include "../mm/singleton.h"
#ifndef FONT_H
#define FONT_H

//Global Font Class (singleton)
class FontLib : public Singleton<FontLib>
{
	//Display list
	GLuint base;
	//OpenGL font values
	GLfloat cnt1;
	GLfloat cnt2;
	
	public:
	//Constructor
	FontLib();
	
	//Destructor
	~FontLib();
	
	//Deallocates font
	void killFont();
	
	//Creates font
	void buildFont( void );
	
	//Prints
	void glPrint( const char *fmt, ... );

};

#endif

