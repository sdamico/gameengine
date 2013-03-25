/*
 * WeaponDisplay.cpp
 *
 *  Created on: Sep 8, 2008
 *      Author: sam
 */

#include "WeaponDisplay.h"

WeaponDisplay::WeaponDisplay()
{
	this->parent = NULL;
	tex = "";
	crosshairTex = "";
}

WeaponDisplay::~WeaponDisplay()
{
}

WeaponDisplay::WeaponDisplay(Object *parent, std::string texture, std::string crosshairTexture)
{
	this->parent = parent;
	tex = texture;
	crosshairTex = crosshairTexture;
}

void WeaponDisplay::setCurrentWeaponLauncher(WeaponLauncher *launcher)
{
	curLauncher = launcher;
}

void WeaponDisplay::render()
{
	if(parent && parent->getObjectType()=="player")
	{
		glDisable(GL_LIGHTING);
		//glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glMaterialfv(GL_FRONT, GL_EMISSION, (const float[4]){1.0f,1.0f,1.0f,1.25f});
		glEnable(GL_BLEND);

		double m[16];
		Camera::get().getMatrix(m);

		glPushMatrix();



		glLoadIdentity();
		Camera::get().setPerspective();


		glPushMatrix();
		glTranslatef(Camera::get().look.x/0.8f,Camera::get().look.y/0.8f,Camera::get().look.z/0.8f);
		glTranslatef(Camera::get().up.x*-0.30f,Camera::get().up.y*-0.30f,Camera::get().up.z*-0.30f);
		glTranslatef(Camera::get().right.x*-0.95f,Camera::get().right.y*-0.95f,Camera::get().right.z*-0.95f);
		glScalef(0.16f,0.16f,0.16f);

		glMultMatrixd(m);
		//glTranslatef(-0.4f,0.5f,1.0f);
		glScalef(0.6f,1.2f,1.0f);
		TextureMgr::get().use(tex);
		glBegin(GL_QUADS);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(1.0f,-1.0f,0.0f);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(-1.0f,-1.0f,0.0f);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(-1.0f,1.0f,0.0f);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(1.0f,1.0f,0.0f);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(Camera::get().look.x/0.8f,Camera::get().look.y/0.8f,Camera::get().look.z/0.8f);
		//glTranslatef(Camera::get().up.x*0.16f,Camera::get().up.y*0.16f,Camera::get().up.z*0.16f);
		//glTranslatef(Camera::get().right.x*-0.16f,Camera::get().right.y*-0.16f,Camera::get().right.z*-0.16f);
		glScalef(0.16f,0.16f,0.16f);
		glMultMatrixd(m);
		//glTranslatef(-1.0f,1.0f,0.0f);
		//glScalef(0.6f,1.2f,1.0f);
		TextureMgr::get().use(crosshairTex);
		glBegin(GL_QUADS);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(1.0f,-1.0f,0.0f);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(-1.0f,-1.0f,0.0f);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(-1.0f,1.0f,0.0f);
				glColor4f(1.0f,1.0f,1.0f,1.0f);
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(1.0f,1.0f,0.0f);
		glEnd();
		glPopMatrix();

		glPopMatrix();
		glPushMatrix();
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glColor4f(0.1f,1.0f,0.0f,1.0f);

		glRasterPos3f(-0.95f,-0.33f,-0.5f);
		FontLib::get().glPrint("Current Weapon(s):");

		if(curLauncher)
		{
			glRasterPos3f(-0.95f,-0.36f,-0.5f);
			FontLib::get().glPrint("%s",curLauncher->getID().c_str());
			glRasterPos3f(-0.95f, -0.39f,-0.5f);
			FontLib::get().glPrint("Remaining Ammunition: %d/%d",curLauncher->getAmmo(),curLauncher->getMaxAmmo());
		}
		else
		{
			glRasterPos3f(-0.95f,-0.36f,-0.5f);
			FontLib::get().glPrint("No Weapon Selected");
		}
		glColor4f(1.0f,1.0f,1.0f,1.0f);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}
