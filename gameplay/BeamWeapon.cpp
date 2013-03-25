#include "BeamWeapon.h"

const double BeamWeapon::BEAM_LENGTH = 100000.0f;

BeamWeapon::BeamWeapon()
{
	this->source = NULL;
	this->position = Vector();
	this->direction = Vector();
	this->beamWidth = 0.0f;
	on = false;
	energy = 100.0f;
	heat = 0.0f;
	overHeat = false;

}

BeamWeapon::~BeamWeapon()
{
}

BeamWeapon::BeamWeapon(Object *source, Vector position, double beamWidth)
{
	this->source = source;
	this->position = position;
	this->direction = source->getLook();
	this->beamWidth = beamWidth;
	on=false;
	energy = 100.0f;
	heat = 0.0f;
	overHeat = false;
}

BeamWeapon::BeamWeapon(Object *source, double beamWidth)
{
	this->source = source;
	this->position = Vector();
	this->direction = source->getLook();
	this->beamWidth = beamWidth;
	on=false;
	energy = 100.0f;
	heat = 0.0f;
	overHeat = false;
}

void BeamWeapon::detectCollision()
{
	if(source && beamWidth)
	{
		Object *o = ObjectMgr::get().detectCollision(source->getPos(),source->getPos()+source->getLook()*BEAM_LENGTH);
		if(o)
		{
			o->handleCollision(NULL);
		}

	}
}

void BeamWeapon::calcHeat()
{
	if(heat<=0.0f)
	{
		overHeat=false;
		heat=0.0f;
	}
	if(heat>100.0f)
	{
		overHeat=true;
		heat=100.0f;
	}
	if(overHeat)on=false;
	if(on)
	{
		heat+=30.0f*GlobalTime::get().frameSec;
	}
	else if(overHeat)
	{
		heat-=30.0f*GlobalTime::get().frameSec;
	}
	else
	{
		heat-=50.0f*GlobalTime::get().frameSec;
	}
}

void BeamWeapon::calcEnergy()
{
	if(on)
	{
		energy-=20.0f*GlobalTime::get().frameSec;
	}
	else
	{
		energy+=10.0f*GlobalTime::get().frameSec;
	}

	if(energy>100.0f)energy = 100.0f;
	else if(energy<5.0f && on)
	{
		on = false;
		energy = 0.0f;
	}
}

void BeamWeapon::activate()
{
	if(!overHeat && energy>5.0f)on=true;
}

void BeamWeapon::render()
{
	if(source && beamWidth && !overHeat && on)
	{
		glPushMatrix();
		glBlendFunc (GL_SRC_ALPHA, GL_ONE);
		direction = source->getLook();

		Vector p = source->getPos();

		glTranslatef(p.x,p.y,p.z);
		double m[16];
		source->getMatrix(m);
		glMultMatrixd(m);

		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		//glMaterialfv(GL_FRONT, GL_EMISSION, (float[4]){1.0f,1.0f,1.0f,1.25f});
		//glDisable(GL_BLEND);



		TextureMgr::get().use("beam");
		glRotatef(90.0f,0.0f,1.0f,0.0f);
		glScalef(BEAM_LENGTH,beamWidth,1.0f);
		glTranslatef(position.z-1.0f,position.y+((double)(rand()%1000))/50000.0f,position.x);

		glBegin(GL_QUADS);
			glColor4f(1.0f,1.0f,1.0f,1.0f);
			glTexCoord2f(0.0f,0.0f);
   	 		glVertex3f(1.0f,-1.0f,0.0f);
			glTexCoord2f(1.0f,0.0f);
			glVertex3f(-1.0f,-1.0f,0.0f);
			glTexCoord2f(1.0f,1.0f);
			glVertex3f(-1.0f,1.0f,0.0f);
			glTexCoord2f(0.0f,1.0f);
			glVertex3f(1.0f,1.0f,0.0f);
			glColor4f(1.0f,1.0f,1.0f,1.0f);
		glEnd();
		//glEnable(GL_BLEND);
		//glDepthMask(GL_TRUE);
		//glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();

		detectCollision();
	}
	calcHeat();
	calcEnergy();
	on=false;
}

double BeamWeapon::getHeat()
{
	return heat;
}

double BeamWeapon::getEnergy()
{
	return energy;
}
