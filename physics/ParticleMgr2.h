#ifndef PARTICLEMGR2_H_
#define PARTICLEMGR2_H_

#include "../res.h"
#include "../mm/singleton.h"
#include "../mm/list.h"
#include "../texture/texturemgr.h"
#include "../time/time.h"
#include "../camera/Camera.h"
#include "../vector/FVector.h"

class ParticleMgr2 : public Singleton<ParticleMgr2>
{
	class ParticleGroup
	{
		std::string id;
		Texture *texptr;
		int numParticles;
		GLuint array;
		struct Particle
		{
			glRGBA curColor;
			FVector pos;
			FVector velocity;
			bool state;
			int type;
			float scale;
			float curScale;
			float endScale;
			float scalestep;
			glRGBA startColor;
			glRGBA endColor;
			long counter;
			float lifetime;
			float fadestep;
		}*particles;
	public:
		ParticleGroup();
		ParticleGroup(std::string id, std::string texture, int numParticles);
		~ParticleGroup();
		std::string getID();
		void startParticle(int type, glRGBA color, float scale, float endScale, long lifetime, Vector ps, Vector v);
		void render();
		void handle();
	};
	List<ParticleGroup> *groups;
public:
	ParticleMgr2();
	virtual ~ParticleMgr2();
	void handle();
	void render();
	void addParticleGroup(std::string id, std::string texture, int numParticles);
	void startParticle(std::string groupID, int type, glRGBA color, float scale, float endScale, long lifetime, Vector ps, Vector v);
};

#endif /*PARTICLEMGR2_H_*/
