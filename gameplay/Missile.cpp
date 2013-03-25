#include "Missile.h"

Missile::Missile()
{
}

Missile::Missile(std::string id, std::string model, Vector pos, Vector velocity, float launchSpeed, Quaternion q, std::string source, std::string target, double mass, float scale)
	: SpaceObject(id,"",model,pos,velocity,mass,scale)
{
	//top speed variable, change to desired top speed,
	topAccel = 200.0f;
	topTurnSpeed = 40.0f;
	thrustVecThreshold = 10.0f;

	acceleration=Vector();

	this->q=q;
	double m[16];
	q.createMatrix(m);
	up.x=m[0];
	up.y=m[1];
	up.z=m[2];
	right.x=m[4];
	right.y=m[5];
	right.z=m[6];
	look.x=m[8];
	look.y=m[9];
	look.z=m[10];

	//Normalize vectors
	up.normalize();
	right.normalize();
	look.normalize();

	collisionID = "";
	lastCollision = 0;

	if(target!="")
		this->target=target;

	done=false;

	this->velocity=velocity+look*launchSpeed;
	this->source=source;
	objectType="missile";
	homeTime = 100000;
	Object *parentObj = ObjectMgr::get().find(source);
	if(parentObj)factionID = parentObj->getFactionID();
	else factionID="";
	startTime=SDL_GetTicks();
}

Missile::~Missile()
{
}

void Missile::handleCollision(Object *other)
{
	if(other==NULL || other->getID()!=source)
	{
		done = true;
		//for(int i=0;i<500;i++)ParticleMgr::get().startParticle(1,(glRGBA){0.4f,0.4f,1.0f,1.0f},"engine",10.0f,100.0f,1000,pos,velocity+(Vector){(((float)(rand()%100))-50.0f)/4.0f,(((float)(rand()%100))-50.0f)/4.0f,(((float)(rand()%100))-50.0f)/4.0f});
		ParticleMgr::get().startExplosion("engine",225,0.1f,4000.0f,700,pos,velocity,300);
	}
}

void Missile::action()
{
	//home for 100s
	if(SDL_GetTicks()-startTime<homeTime)
	{
		track(target);
		ParticleMgr::get().startParticle(1,(glRGBA){0.2f,0.2f,1.0f,1.0f},"engine",size*scale*3.0f,size*scale*6.0f,100,pos-look*size*scale*.5,velocity-look*15+Vector((((float)(rand()%100))-50.0f)/10000.0f,(((float)(rand()%100))-50.0f)/10000.0f,(((float)(rand()%100))-50.0f)/1000.0f));
	}
}

std::string Missile::getTargetID()
{
	return target;
}
