#include "Radar.h"

Radar::Radar()
{
	targeting=NULL;
	range = 3000.0f;
	tex="";
	zoom=false;
}

Radar::Radar(TargetingSystem *targeting, std::string texture)
{
	this->targeting=targeting;
	range=30000.0f;
	tex=texture;
	zoom=false;
}

Radar::~Radar()
{
}

void Radar::toggleZoom()
{
	if(zoom)
	{
		zoom=false;
		range=range/10;
	}
	else
	{
		zoom=true;
		range=range*10;
	}
}

void Radar::render()
{
	glDisable(GL_LIGHTING);
	glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	double m[16];
	Camera::get().getMatrix(m);

	glPushMatrix();

	glLoadIdentity();

	Camera::get().setPerspective();

	glTranslatef(Camera::get().look.x/0.8f,Camera::get().look.y/0.8f,Camera::get().look.z/0.8f);
	glTranslatef(Camera::get().up.x*-0.52f,Camera::get().up.y*-0.52f,Camera::get().up.z*-0.52f);
	glScalef(0.16f,0.16f,0.16f);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glPushMatrix();
	List<Object> *list = ObjectMgr::get().getList();
	if(list)
	{
		ListElement<Object> *le = list->getCurrent();
		list->resetList();

		Vector p;
		Vector l;



		glScalef(1/range,1/range,1/range);

		glMaterialfv(GL_BACK, GL_EMISSION, (const float[4]){1.0f,1.0f,1.0f,1.25f});

		glPointSize(2.0f);

		glDepthMask(GL_FALSE);

		//glBlendFunc (GL_SRC_ALPHA, GL_ONE);

		glEnable(GL_POINT_SPRITE);

		glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

		glEnable(GL_POINT_SMOOTH);

		glPointParameterfv(GL_POINT_SIZE_MAX, (const float[1]){15.0f});



		glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, (const GLfloat[3]){0.0f,0.0f,0.0f});

		glPointSize(10.0f);


		Texture *enemy = TextureMgr::get().find("radaricon");
		Texture *friendly = TextureMgr::get().find("radariconfriendly");
		Texture *weapon = TextureMgr::get().find("radariconweapon");
		Texture *target = TextureMgr::get().find("radariconcurtarget");

		while(1)
		{
			p=list->currentElement()->getPos()-targeting->getParent()->getPos();
			l=list->currentElement()->getLook();
			if(p.magnitude()<=range)
			{
				if(targeting->getTargetID()==list->currentElement()->getID())
				{
					target->bind();
				}
				/*else if(targeting->getParent()->getID()==list->currentElement()->getID())
					glColor4f(0.0f,0.0f,0.0f,1.0f);*/
				else if(list->currentElement()->getObjectType()=="missile")
					weapon->bind();
				else if(targeting->getParent()->getFactionID()==list->currentElement()->getFactionID())
					friendly->bind();
				else
					enemy->bind();
				glBegin(GL_POINTS);
				glVertex3f(p.x,p.y,p.z);
				glEnd();
			}
			if(!list->nextElement()) break;
		}
		glColor4f(1.0f,1.0f,1.0f,1.0f);


		glDisable(GL_POINT_SMOOTH);
		glDisable(GL_POINT_SPRITE);
		glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_FALSE);
		glDepthMask(GL_TRUE);

		list->setCurrent(le);
	}

	glPopMatrix();



	glPushMatrix();

	glMultMatrixd(m);
	//glTranslatef(-0.75f,0.0f,1.0f);
	glScalef(1.25f,1.25f,1.0f);

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



	glPopMatrix();

	glEnable(GL_LIGHTING);
}
