#ifndef STARFIELD_H_
#define STARFIELD_H_

#include "../model/ModelMgr.h"
#include "../camera/Camera.h"

class StarField
{
	Model *m;
public:
	StarField();
	StarField(std::string m);
	virtual ~StarField();
	void Render();
};

#endif /*STARFIELD_H_*/
