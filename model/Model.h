#ifndef MODEL_H_
#define MODEL_H_

#include "../vector/FVector.h"

class Model
{
protected:
	float sphereRadius;
	float scale;
public:
	std::string id;
	Model();
	virtual ~Model();
	std::string getID();
	float getSphereRadius();
	virtual void release();
	virtual void render();
	//virtual void Load(string id, string file);
};

#endif /*MODEL_H_*/
