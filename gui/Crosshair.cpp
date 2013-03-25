#include "Crosshair.h"

Crosshair::Crosshair()
{
}

Crosshair::Crosshair(std::string ident, Vector topLeft, Vector bottomRight)
{
	init(ident,"","",topLeft,bottomRight,NULL);
}

Crosshair::~Crosshair()
{
	
}

void Crosshair::render()
{
	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	
	glBegin(GL_LINES);
		glColor4f(0.0f,1.0f,0.0f,1.0f);
		glVertex2f((posTopLeft.x+posBottomRight.x)/2.0f,(posTopLeft.y+posBottomRight.y)/2.0f);
		glVertex2f((posTopLeft.x+posBottomRight.x)/2.0f,posTopLeft.y);
		glVertex2f((posTopLeft.x+posBottomRight.x)/2.0f,(posTopLeft.y+posBottomRight.y)/2.0f);
		glVertex2f((posTopLeft.x+posBottomRight.x)/2.0f,posBottomRight.y);
		glVertex2f((posTopLeft.x+posBottomRight.x)/2.0f,(posTopLeft.y+posBottomRight.y)/2.0f);
		glVertex2f(posTopLeft.x,(posTopLeft.y+posBottomRight.y)/2.0f);
		glVertex2f((posTopLeft.x+posBottomRight.x)/2.0f,(posTopLeft.y+posBottomRight.y)/2.0f);
		glVertex2f(posBottomRight.x,(posTopLeft.y+posBottomRight.y)/2.0f);
		glColor4f(1.0f,1.0f,1.0f,1.0f);
	glEnd();
	
	glRasterPos2f(posTopLeft.x+0.05f,posTopLeft.y+0.1f);
	FontLib::get().glPrint("%s",text.c_str());
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	
	glPopMatrix();
}
