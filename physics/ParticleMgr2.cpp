#include "ParticleMgr2.h"

ParticleMgr2::ParticleMgr2()
{
	groups = new List<ParticleGroup>;
}

ParticleMgr2::~ParticleMgr2()
{
	delete groups;
}

void ParticleMgr2::handle()
{
	groups->resetList();
	if(groups->currentElement())
	{
		while(1)
		{
			groups->currentElement()->handle();
			if(!groups->nextElement())break;
		}
	}
}

void ParticleMgr2::render()
{
	groups->resetList();
	if(groups->currentElement())
	{
		while(1)
		{
			groups->currentElement()->render();
			if(!groups->nextElement())break;
		}
	}
}

void ParticleMgr2::addParticleGroup(std::string id, std::string texture, int numParticles)
{
	groups->addElement(new ParticleGroup(id, texture, numParticles));
}

void ParticleMgr2::startParticle(std::string groupID, int type, glRGBA color, float scale, float endScale, long lifetime, Vector ps, Vector v)
{
	ParticleGroup *g = groups->find(groupID);
	if(g)g->startParticle(type,color,scale,endScale,lifetime,ps,v);
}

ParticleMgr2::ParticleGroup::ParticleGroup()
{
	id="";
	texptr=NULL;
	particles=NULL;
}

ParticleMgr2::ParticleGroup::ParticleGroup(std::string id, std::string texture, int numParticles)
{
	this->id = id;
	texptr = TextureMgr::get().find(id);
	this->numParticles=numParticles;
	particles = new Particle[numParticles];



	/*
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, buffer[0]);
	glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, ( numFaces )*sizeof(Face), face, GL_STATIC_DRAW_ARB);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, buffer[1]);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, ( numFaces * 3 )*sizeof(float), vertex, GL_STATIC_DRAW_ARB);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, buffer[2]);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, ( numFaces * 3 )*sizeof(float), normal, GL_STATIC_DRAW_ARB);*/
}

ParticleMgr2::ParticleGroup::~ParticleGroup()
{
	if(particles) delete particles;
}

std::string ParticleMgr2::ParticleGroup::getID()
{
	return id;
}

void ParticleMgr2::ParticleGroup::startParticle(int type, glRGBA color, float scale, float endScale, long lifetime, Vector ps, Vector v)
{
	int pindex=-1;
	for(int i=0;i<numParticles;i++)
	if(particles[i].state==0)
	{
		pindex=i;
		break;
	}
	if(pindex==-1) return;

	particles[pindex].state=1;
	particles[pindex].type=type;
	particles[pindex].pos=(FVector){ps.x,ps.y,ps.z};
	particles[pindex].velocity=(FVector){v.x,v.y,v.z};
	particles[pindex].counter=SDL_GetTicks();
	particles[pindex].lifetime=lifetime;
	particles[pindex].fadestep=color.a/((float)lifetime);
	particles[pindex].scale=scale;
	particles[pindex].curScale=scale;
	particles[pindex].endScale=endScale;
	particles[pindex].scalestep=(endScale-scale)/((float)lifetime);
	particles[pindex].startColor=color;
	particles[pindex].endColor=color;
	particles[pindex].endColor.a=0;

	if(type==1){
		particles[pindex].curColor=color;
	}
	if(type==0){
		particles[pindex].curColor=color;
		particles[pindex].curColor.a=(rand()%100)/100;
	}
}

void ParticleMgr2::ParticleGroup::render()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glMaterialfv(GL_BACK, GL_EMISSION, (const float[4]){1.0f,1.0f,1.0f,1.25f});
	glEnable (GL_BLEND);
	glDepthMask(GL_FALSE);

	glBlendFunc (GL_SRC_ALPHA, GL_ONE);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//glPointSize(4.0f);


	glEnable(GL_POINT_SPRITE);
	glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

	glEnable(GL_POINT_SMOOTH);
	glPointSize(5.0f);
	glPointParameterfv(GL_POINT_SIZE_MAX, (const float[1]){5000.0f});

	if(texptr)texptr->bind();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	//glInterleavedArrays(GL_C4UB_V3F,sizeof(Particle)-4*7,particles);
	glVertexPointer(3, GL_FLOAT, sizeof(Particle), particles);
	glColorPointer(4, GL_FLOAT, sizeof(Particle), &particles[0].curColor.r);
	glDrawArrays(GL_POINTS, 0, numParticles);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glColor4f(1.0f,1.0f,1.0f,1.0f);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_POINT_SPRITE);
	glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_FALSE);

	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void ParticleMgr2::ParticleGroup::handle()
{
	//float t=(globalTime);
	numParticles=0;
	for(int i=0;i<numParticles;i++)
	{
		if(particles[i].state==1)
		{
			if(!Camera::get().sphereInFrustum(Vector(particles[i].pos.x,particles[i].pos.y,particles[i].pos.z),particles[i].curScale*.03))particles[i].state=0;
			else {
				numParticles++;
				particles[i].pos+=particles[i].velocity*(GlobalTime::get().frameSec);

				particles[i].curScale+=particles[i].scalestep*(GlobalTime::get().frameTime);
				if(particles[i].type==0)
				{
					particles[i].curColor.a=((float)(rand()%100))/100;
					if((SDL_GetTicks()-particles[i].counter)>particles[i].lifetime)
					{
						particles[i].state=0;
					}

				}

				if(particles[i].type==1)
				{

					float t=(float)(SDL_GetTicks()-particles[i].counter);
					particles[i].curColor.a-=particles[i].fadestep*(GlobalTime::get().frameTime);
					if(t>particles[i].lifetime)
					{

						particles[i].state=0;
					}

				}
			}
		}
	}
}
